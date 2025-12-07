#ifndef _EMAC_H_
#define _EMAC_H_

#include "types.h"

/**
 * @brief Регистры Ethernet EMAC
 */

/**
 * @brief Структуры и перечисления Ethernet EMAC
 */

typedef union {
  u32 registers[28];
  struct {
    u32 mac_csr;
  };
} emac_cfg_t;

typedef enum : u8 {
  NO_ERR = 0x00,

  ERR_ARGUMENT = 0x01,
} emac_status_t;

typedef union {
  u64 qword;
  struct {
    u32 desc1;
    u32 desc2;
  };
} emac_descriptor_t;

typedef struct {
#define EMAC_MACLEN 6
  u8  dst[EMAC_MACLEN];
  u8  src[EMAC_MACLEN];
  u16 type;
} emac_header_t;

typedef struct {
  emac_header_t hdr;
#define EMAC_DATALEN 1500
  u8 data[EMAC_DATALEN];
} emac_frame_t;

emac_status_t
emac_init(const u8 channel, const emac_cfg_t *emac_cfg);

emac_status_t
emac_send(const u8 channel, const emac_frame_t *frame, const u16 data_len);

emac_status_t
emac_send_raw(const u8 channel, const u8 *data, const u16 data_len);

emac_status_t
emac_receive(const u8 channel, emac_frame_t *frame, u16 *data_len);

emac_status_t
emac_receive_raw(const u8 channel, u8 *data, u16 *data_len);

#endif  // _EMAC_H_
