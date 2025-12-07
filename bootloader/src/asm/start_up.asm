.set noreorder
.set mips32
.text

# Точка входа в программу
_start: .global _start
    .ent _start
    la $28, _gp
    la $29, __stack

    # Очистка области неинициализированных переменных
    la $2, __bss_start
    la $4, __bss_end
    beq $2, $4, 2f
    nop

1:  sw $0, 0($2)
    addiu $2, 4
    bne $2, $4, 1b
    nop

    # Переход на main()
2:  lui $2, %hi(main)
    ori $2, %lo(main)
    jr $2
    nop

3:  b 3b
    nop
    .end _start
