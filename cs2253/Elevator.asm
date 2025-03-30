.data
current_floor: .word 1
prompt: .asciiz "\nEnter a floor number: "
elevatorFloor: .asciiz "\nElevator is on floor: " #$s0
menu_options: .asciiz "\n1: Request Floor\n2: Run Elevator\n3: Emergency Stop\n4: Reset\nChoice: "
differentFloor: .asciiz "\nError: Elevator and person are on different floors\nCall the elevator first\n"
wrongChoice: .asciiz "\nError: Invalid choice\n"
outOfBounds: .asciiz "\nError: Invalid floor selection. Choose between 1 and 5.\n"
onFloor: .asciiz "\nCurrenty on floor: "
requests: .space 20 #creating the array in memory
requestFloorMSG: .asciiz "\nEnter the floor number to call the elevator to: "
emergencyMSG: .asciiz "\nEmergency mode activated. Elevator is not in service.\n"
resetMSG: .asciiz "\nElevator has been reset to floor 1.\n"
.text
main:



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
    la $a0, menu_options 
    syscall

    li $v0, 5
    syscall

    move $t0, $v0

    #branches to whatever is chosen in the menu
    beq $t0, 0, setEmergency
    beq $t0, 1, callElevatorToFloor
    beq $t0, 2, movePersonAndElevatorToFloor 
    beq $t0, 3, reset
    beq $t0, 4, exit

    # if any value other than whats showed on menu is entered 
    # this will be printed and the menu will be called again
    li $v0, 4
    la $a0, wrongChoice 
    syscall

    j menu

setEmergency:
    # set the elevator to emergency mode
    li $s2, 1

    # print the emergency message
    li $v0, 4
    la $a0, emergencyMSG 
    syscall

    # return to menu
    j menu

reset:
    # reset the elevator to floor 1
    li $s0, 1

    # print the reset message
    li $v0, 4
    la $a0, resetMSG 
    syscall

    li $v0, 1
    move $a0, current_floor
    syscall

    #clear requests
    la $t0, requests
    li $t1, 20
    li $t2, 0        

    # return to menu
    j menu



requestElevator:
    #Eneter floor to call the elevator to 
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    # check if call is in floor range (1-5)
    blt $v0, 1, invalid_floor
    bgt $v0, 5, invalid_floor

    la $t0, requests
    sub $t1, $v0, 1        
    sll $t1, $t1, 2         
    add $t0, $t0, $t1
    li $t1, 1
    sw $t1, 0($t0)


    
movingUp:
    addi $s0, $s0, 1
    li $a0, 1000
    jal delay
    li $v0, 4
    la $a0, onFloor
    syscall
    li $v0, 1
    move $a0, $s0
    syscall
    bgt $t1, $s0, movingUp
    j movingDown
    
movingDown:
    beq $t1, $s0, menu
    addi $s0, $s0, -1
    li $a0, 1000
    jal delay
    li $v0, 4
    la $a0, onFloor
    syscall
    li $v0, 1
    move $a0, $s0
    syscall
    j movingDown
    
    #delay

delay:
li $v0, 32
syscall
jr $ra

movePersonAndElevatorToFloor:
    # if person and elevator are on different floors
    # this will be printed and the menu will be called again
    bne $s0, $s1, error

    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall

# check if call is in floor range (1-5)
    blt $v0, 1, invalid_floor
    bgt $v0, 5, invalid_floor

    # moves the person and elevator to the same floor
    move $t1, $v0
    move $s1, $v0
    bgt $t1, $s0, movingUp
    j movingDown
    move $s1, $v0

    j menu

error:
    li $v0, 4
    la $a0, differentFloor
    syscall

    j menu

invalid_floor:
    li $v0, 4
    la $a0, outOfBounds
    syscall
    j Offmenu

exit:
    li $v0, 10
    syscall
