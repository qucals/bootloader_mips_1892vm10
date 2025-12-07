OUTPUT_FORMAT("elf32-littlemips")
OUTPUT_ARCH(mips)

ENTRY(_start)

MEMORY {
    CRAM (rwx) : ORIGIN = 0xb8000000, LENGTH = 0x1ffff
}

__stack_size = 0x2000;

SECTIONS {
    .text : ALING(4) {
        *(.text)
        *(.text.*)

        *(.rodata)
        *(.rodata.*)
    } > CRAM

    .data : ALIGN(4) {
        *(.data)
        *(.data.*)
    } > CRAM

    .bss : ALIGN(4) {
        __bss_start = .;
        
        *(.bss)
        *(.bss.*)
        *(COMMON)

        __bss_end = .;
    } > CRAM

    .stack : ALIGN(4) {
        __stack_end = .;
        . = . + __stack_size;
        __stack_top = .;
    } > CRAM

    /*
    .heap : ALIGN(4) {
        __heap_start = .;
        . = . + __heap_size;
        __heap_end = .;
    } > CRAM
    */
}
