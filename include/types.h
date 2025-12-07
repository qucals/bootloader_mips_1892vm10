#ifndef _TYPES_H_
#define _TYPES_H_

#include <limits.h>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uintptr_t uintptr;

typedef uintptr vhys_addr_t;
typedef uintptr phys_addr_t;

typedef void* vptr;

typedef void (*fn_ptr)();

#endif  // _TYPES_H_
