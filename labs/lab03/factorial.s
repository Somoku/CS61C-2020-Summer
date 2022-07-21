.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    mv t1, a0
    addi a0, x0, 1
loop:
    beq t1, x0, loop_end
    mul a0, a0, t1
    addi t1, t1, -1
    jal x0, loop
loop_end:
    jr ra