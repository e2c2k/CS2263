.data
prompt: .asciiz "\nEnter a floor number: "
elevatorFloor: .asciiz "\nElevator is on floor " #$s0
personFloor: .asciiz "\nYou're on floor " #$s1
menuChoice: .asciiz "\n1. Call Elevator\n2. Use Elevator \n3. Exit\n"
differentFloor: .asciiz "\nError: Elevator and person are on different floors\nCall the elevator first\n"
.text
main:

    li $s0, 0 # elevator starts on floor 0
    li $s1, 0 # person starts on floor 0

    jal menu

menu:
    li $v0, 4
    la $a0, elevatorFloor
    syscall

    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 4
    la $a0, personFloor
    syscall 

    li $v0, 1
    move $a0, $s1
    syscall

    li $v0, 4
    la $a0, menuChoice
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    beq $t0, 1, callElevatorToFloor
    beq $t0, 2, movePersonAndElevatorToFloor
    beq $t0, 3, exit

    j menu

callElevatorToFloor:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall

    move $s0, $v0

    jal menu

    j callElevatorToFloor

movePersonAndElevatorToFloor:

    bne $s0, $s1, error

    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall

    move $s0, $v0
    move $s1, $v0

    jal menu

    j movePersonAndElevatorToFloor


error:
    li $v0, 4
    la $a0, differentFloor
    syscall

    jal menu

    j error

exit:
    li $v0, 10
    syscall