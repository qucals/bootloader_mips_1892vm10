#ifndef _TYPES_H_
#define _TYPES_H_

// Типы данных
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;

typedef signed char  i8;
typedef signed short i16;
typedef signed int   i32;
typedef signed long  i64;

typedef u32 uintptr;
typedef u32 usize;

typedef volatile u8  reg8_t;
typedef volatile u16 reg16_t;
typedef volatile u32 reg32_t;

typedef u8 boolean;
#define FALSE 0
#define TRUE  1

#define vptr void *

#define NULL 0

// Битовые операции
#define BIT(n) (1U << (n))

#define BIT_SET(reg, bit) ((reg) |= BIT(bit))
#define BIT_CLR(reg, bit) ((reg) &= ~BIT(bit))
#define BIT_TGL(reg, bit) ((reg) ^= BIT(bit))
#define BIT_GET(reg, bit) (((reg) >> (bit)) & 1U)

// Доступ к регистрам по адресу
#define REG8(addr)  (*(volatile u8 *)(addr))
#define REG16(addr) (*(volatile u16 *)(addr))
#define REG32(addr) (*(volatile u32 *)(addr))
#define REG(addr)   REG32(addr)

#define LINKER_VAR(name) extern u8 name[]

#endif  // _TYPES_H_
