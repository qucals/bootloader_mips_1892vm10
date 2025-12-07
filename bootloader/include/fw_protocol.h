#ifndef _FW_PROTOCOL_H_
#define _FW_PROTOCOL_H_

#include "types.h"

#define FWPROTO_EMAC_TYPE 0x8080
#define FWPROTO_EMAC_SRC \
  {                      \
  }

typedef enum : u8 {
  NO_ERR = 0x00,

  FW_ERR_ARGUMENTS  = 0xE1,
  FW_ERR_CONNECTION = 0xE2,
} fwproto_status_t;

typedef struct {
  u16 seq;
  u8  cmd;
  u32 len;
#define FWPROTO_DATALEN (1493)
  u8 data[FWPROTO_DATALEN];
} fwproto_packet_t;

typedef struct {
  u32 load_addr;
  u32 total_size;
  u16 chunk_counts;
#define FWPROTO_CHUNKS_MAXLEN (FWPROTO_DATALEN - 10)
  u16 chunk_lens[FWPROTO_CHUNKS_MAXLEN];
} fwproto_cfg_packet_t;

void
fwproto_set_timeout_for_all(const u32 timeout_ms);

fwproto_status_t
fwproto_init(const u8 channel);

fwproto_status_t
fwproto_wait_conn();

fwproto_status_t
fwproto_wait_close();

fwproto_status_t
fwproto_conn();

fwproto_status_t
fwproto_close();

fwproto_status_t
fwproto_send(const fwproto_packet_t *packet, const u16 len);

fwproto_status_t
fwproto_receive(fwproto_packet_t *packet, u16 *len);

fwproto_status_t
fwproto_get_cfg_packet(fwproto_cfg_packet_t *cfg_packet, u16 *chunks_len);

#endif  // _FW_PROTOCOL_H_
