.data
floors: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
current_floor: .word 1            # preset to floor 1
requests: .space 40               # 10 floor requests (10 * 4 bytes = 40 bytes)
request_count: .word 0            # number of requests
emergency_flag: .word 0           # 0 for normal, 1 for emergency
floor_prompt: .asciiz "\nCurrent floor: "
menu_options: .asciiz "\n1: Request Floor\n2: Run Elevator\n3: Emergency Stop\n4: Reset\n5: Exit\nChoice: "
enter_floor_prompt: .asciiz "\nEnter floor (1-10): "
direction_message: .asciiz "\nMoving "
up_message: .asciiz "UP\n"
down_message: .asciiz "DOWN\n"
emergency_message: .asciiz "\nEmergency Stop Activated!\n"
queue_full_message: .asciiz "\nRequest queue full!\n"
emergency_active_message: .asciiz "\nElevator in emergency mode. Reset required (4).\n"
invalid_input_message: .asciiz "\nInvalid input!\n"
invalid_floor_message: .asciiz "\nInvalid floor! Please enter 1-10.\n"

.text
.globl main

main:
    # Display current floor
    li $v0, 4
    la $a0, floor_prompt
    syscall
    
    li $v0, 1
    lw $a0, current_floor
    syscall

    j menu

menu:
    # Display menu
    li $v0, 4
    la $a0, menu_options
    syscall
    
    # Get menu choice
    li $v0, 5
    syscall
    move $t0, $v0
    
    # Process menu choice
    beq $t0, 1, request_floor
    beq $t0, 2, process_requests
    beq $t0, 3, set_emergency
    beq $t0, 4, reset_emergency
    beq $t0, 5, exit_program
    
    # Invalid input
    li $v0, 4
    la $a0, invalid_input_message
    syscall
    j menu

request_floor:
    lw $t9, emergency_flag
    beq $t9, 1, emergency_active

    li $v0, 4
    la $a0, enter_floor_prompt
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    # Validate floor (1-10)
    blt $t0, 1, invalid_floor
    bgt $t0, 10, invalid_floor
    
    # Add to request queue
    lw $t2, request_count
    bge $t2, 10, queue_full
    
    la $t3, requests
    sll $t4, $t2, 2
    add $t3, $t3, $t4
    sw $t0, 0($t3)
    addi $t2, $t2, 1
    sw $t2, request_count
    
    j menu

queue_full:
    li $v0, 4
    la $a0, queue_full_message
    syscall
    j menu

invalid_floor:
    li $v0, 4
    la $a0, invalid_floor_message
    syscall
    j menu

process_requests:
    lw $t9, emergency_flag
    beq $t9, 1, emergency_active

    lw $t2, request_count
    beq $t2, 0, menu  # No requests, return to menu
    
    la $t3, requests
    lw $t1, current_floor  # Load current floor

    # Process requests sequentially
    li $t5, 0  # Direction flag (1 for up, -1 for down)
    
process_loop:
    lw $t0, 0($t3)         # Load next request
    beqz $t0, done_processing # Exit loop if no more requests
    addi $t3, $t3, 4       # Move to the next request in queue

    # If the request is greater than current floor, go up
    bgt $t0, $t1, move_up
    # If the request is less than current floor, go down
    blt $t0, $t1, move_down
    j process_loop

move_up:
    # Print Moving UP message
    li $v0, 4
    la $a0, direction_message
    syscall
    la $a0, up_message
    syscall

    # Move up floor by floor
    loop_up:
        addi $t1, $t1, 1        # Go to the next floor
        li $v0, 4
        la $a0, floor_prompt
        syscall
        li $v0, 1
        move $a0, $t1
        syscall
        # Delay for effect
        jal delay
        # Check if we've reached the requested floor
        beq $t1, $t0, next_request  # Stop if reached requested floor
        j loop_up

move_down:
    # Print Moving DOWN message
    li $v0, 4
    la $a0, direction_message
    syscall
    la $a0, down_message
    syscall

    # Move down floor by floor
    loop_down:
        subi $t1, $t1, 1        # Go to the previous floor
        li $v0, 4
        la $a0, floor_prompt
        syscall
        li $v0, 1
        move $a0, $t1
        syscall
        # Delay for effect
        jal delay
        # Check if we've reached the requested floor
        beq $t1, $t0, next_request  # Stop if reached requested floor
        j loop_down

next_request:
    # Update current floor to the last requested floor
    sw $t1, current_floor

    # Check if there's another request
    lw $t0, 0($t3)
    bnez $t0, process_loop  # Continue with next request if available

done_processing:
    # All requests processed, return to menu
    li $v0, 4


    # Clear request queue after processing
    sw $zero, request_count  # Reset request count
    la $t3, requests
    li $t2, 0
clear_requests:
    sw $zero, 0($t3)       # Clear request data
    addi $t3, $t3, 4
    addi $t2, $t2, 1
    bge $t2, 10, clear_done
    j clear_requests
clear_done:

    j menu

set_emergency:
    lw $t9, emergency_flag
    bne $t9, 0, menu    # Already in emergency mode
    
    li $t9, 1
    sw $t9, emergency_flag

    li $v0, 4
    la $a0, emergency_message
    syscall

    j menu

reset_emergency:
    lw $t9, emergency_flag
    beq $t9, 0, menu    # No emergency to reset
    
    li $t9, 0
    sw $t9, emergency_flag
    sw $zero, request_count
    li $v0, 4
    la $a0, floor_prompt
    syscall
    
    li $v0, 1
    lw $a0, current_floor
    syscall
    j menu

emergency_active:
    li $v0, 4
    la $a0, emergency_active_message
    syscall
    j menu

exit_program:
    li $v0, 10     # Exit system (exit the program)
    syscall

delay:
    li $t5, 4000000
delay_loop:
    addi $t5, $t5, -1
    bnez $t5, delay_loop
    jr $ra
