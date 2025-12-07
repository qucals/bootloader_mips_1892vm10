#ifndef _FIRMWARE_H_
#define _FIRMWARE_H_

#include "types.h"

typedef enum : u8 {
  NO_ERR = 0x00,
} fw_status_t;

typedef void (*fw_entry_t)(void);

typedef struct {
  u8   *base;
  usize size;
  usize capacity;
} fw_image_t;

fw_status_t
fw_init(fw_image_t *fw);

fw_status_t
fw_append(fw_image_t *fw, u8 *data, usize len);

fw_status_t
fw_finalize(fw_image_t *fw);

fw_status_t
fw_jump(fw_image_t *fw);

#endif  // _FIRMWARE_H_
