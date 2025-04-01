.data
floors: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
current_floor: .word 1 #preset to floor 1
requests: .space 40    # 10 floor requests because 10 floors
request_count: .word 0  # number of requests
emergency_flag: .word 0 # 0 for normal 1 for emergency
floor_prompt: .asciiz "\nCurrent floor: "
menu_options: .asciiz "\n1: Request Floor\n2: Run Elevator\n3: Emergency Stop\n4: Reset\nChoice: "
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
    
    # Add to queue
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
    beq $t2, 0, main
    
    la $t3, requests
    lw $t1, current_floor
    
process_loop:
    lw $t0, 0($t3)
    
    beq $t0, $t1, next_request
    
    bgt $t0, $t1, move_up
    blt $t0, $t1, move_down

move_up:
    li $v0, 4
    la $a0, direction_message
    syscall
    
    la $a0, up_message
    syscall
    
    move $t4, $t1
    
    loop_up:
        addi $t4, $t4, 1
        li $v0, 4
        la $a0, floor_prompt
        syscall
        
        li $v0, 1
        move $a0, $t4
        syscall
        
        jal delay
        
        beq $t4, $t0, arrive
        j loop_up

move_down:
    li $v0, 4
    la $a0, direction_message
    syscall
    
    la $a0, down_message
    syscall
    
    move $t4, $t1
    
    loop_down:
        subi $t4, $t4, 1
        li $v0, 4
        la $a0, floor_prompt
        syscall
        
        li $v0, 1
        move $a0, $t4
        syscall
        
        jal delay
        
        beq $t4, $t0, arrive
        j loop_down

arrive:
    sw $t0, current_floor
    move $t1, $t0

next_request:
    addi $t3, $t3, 4
    subi $t2, $t2, 1
    sw $t2, request_count
    bgtz $t2, process_loop
    j menu

set_emergency:
    lw $t9, emergency_flag
    bne $t9, 0, main    # Already in emergency mode
    
    li $t9, 1
    sw $t9, emergency_flag


    li $v0, 4
    la $a0, emergency_message
    syscall

    j menu

reset_emergency:
    lw $t9, emergency_flag
    beq $t9, 0, main    # No emergency to reset
    
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

delay:
    li $t5, 8000000
delay_loop:
    addi $t5, $t5, -1
    bnez $t5, delay_loop
    jr $ra