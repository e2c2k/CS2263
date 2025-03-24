.data
prompt: .asciiz "\nEnter a floor number: "
elevatorFloor: .asciiz "\nElevator is on floor " #$s0
personFloor: .asciiz "\nYou're on floor " #$s1
menuChoice: .asciiz "\n1. Call Elevator\n2. Use Elevator \n3. Exit\n"
differentFloor: .asciiz "\nError: Elevator and person are on different floors\nCall the elevator first\n"
wrongChoice: .asciiz "\nError: Invalid choice\n"
.text
main:

    li $s0, 0 # elevator starts on floor 0
    li $s1, 0 # person starts on floor 0

    j menu

menu:
    # print the elevators floor
    li $v0, 4
    la $a0, elevatorFloor 
    syscall

    li $v0, 1
    move $a0, $s0
    syscall

    # print the persons floor
    li $v0, 4
    la $a0, personFloor 
    syscall 

    li $v0, 1
    move $a0, $s1
    syscall

    # prints the menu for what to do next
    li $v0, 4
    la $a0, menuChoice 
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    #branches to whatever is chosen in the meny
    beq $t0, 1, callElevatorToFloor
    beq $t0, 2, movePersonAndElevatorToFloor 
    beq $t0, 3, exit

    # if any value other than whats showed on menu is entered 
    # this will be printed and the menu will be called again
    li $v0, 4
    la $a0, wrongChoice 
    syscall

    j menu

callElevatorToFloor:
    #Eneter floor to call the elevator to 
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall

    move $s0, $v0

    j menu

movePersonAndElevatorToFloor:
    # if person and elevator are on different floors
    # this will be printed and the menu will be called again
    bne $s0, $s1, error

    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall

    # moves the person and elevator to the same floor
    move $s0, $v0
    move $s1, $v0

    j menu

error:
    li $v0, 4
    la $a0, differentFloor
    syscall

    j menu

exit:
    li $v0, 10
    syscall