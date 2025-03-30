.data
floors: .word 1, 2, 3, 4, 5  # Define available floors
current_floor: .word 1       # Elevator starts at floor 1
direction: .word 1           # 1 for up, -1 for down
request_queue: .space 20     # Space to store floor requests (5 requests max)
num_requests: .word 0        # Number of requests
emergency_flag: .word 0      # Emergency stop flag
alarm_flag: .word 0          # Alarm flag
msg_floor: .asciiz "Current Floor: "
msg_request: .asciiz "Enter floor request (1-5) or 0 for emergency: "
msg_moving_up: .asciiz "Moving Up\n"
msg_moving_down: .asciiz "Moving Down\n"
msg_stop: .asciiz "Stopping at floor "
msg_emergency: .asciiz "EMERGENCY STOP ACTIVATED!\n"
msg_alarm: .asciiz "ALARM ACTIVATED!\n"
msg_reset: .asciiz "Press 9 to reset emergency: "

.text
main:
    # Display current floor
    li $v0, 4
    la $a0, msg_floor
    syscall
    lw $a0, current_floor
    li $v0, 1
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall

    # Request user input
    li $v0, 4
    la $a0, msg_request
    syscall
    li $v0, 5
    syscall
    move $t0, $v0  # Store user input

    # Emergency stop check
    beq $t0, 0, emergency_stop

    # Add floor request to queue if valid (1-5)
    blt $t0, 1, main
    bgt $t0, 5, main
    jal add_request

    # Process requests
    jal process_requests

    j main  # Loop back to take new requests

# Emergency Stop Routine
emergency_stop:
    li $v0, 4
    la $a0, msg_emergency
    syscall
    sw $zero, emergency_flag  # Set flag
    li $v0, 4
    la $a0, msg_reset
    syscall
    li $v0, 5
    syscall
    bne $v0, 9, emergency_stop
    j main

# Add Request to Queue
add_request:
    lw $t1, num_requests
    la $t2, request_queue
    sll $t3, $t1, 2  # Offset calculation
    add $t2, $t2, $t3
    sw $t0, 0($t2)  # Store request
    addi $t1, $t1, 1
    sw $t1, num_requests
    jr $ra

# Process Requests
process_requests:
    lw $t1, num_requests
    beqz $t1, end_movement  # No requests, exit

    lw $t2, request_queue  # Get first request
    lw $t3, current_floor

    # Decide direction
    bgt $t2, $t3, move_up
    blt $t2, $t3, move_down

move_up:
    li $v0, 4
    la $a0, msg_moving_up
    syscall
    addi $t3, $t3, 1
    sw $t3, current_floor
    j check_reached

move_down:
    li $v0, 4
    la $a0, msg_moving_down
    syscall
    subi $t3, $t3, 1
    sw $t3, current_floor

check_reached:
    beq $t2, $t3, stop_elevator
    j process_requests

stop_elevator:
    li $v0, 4
    la $a0, msg_stop
    syscall
    lw $a0, current_floor
    li $v0, 1
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall
    j main

end_movement:
    jr $ra
