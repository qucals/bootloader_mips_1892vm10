#include "../include/emac.h"

emac_status_t
emac_init(const u8 channel, const emac_cfg_t *emac_cfg)
{
  if (!emac_cfg) { return ERR_ARGUMENT; }
  // init for all emac registers
  return NO_ERR;
}

emac_status_t
emac_send(const u8 channel, const emac_frame_t *frame, const u16 data_len)
{
  return NO_ERR;
}

emac_status_t
emac_send_raw(const u8 channel, const u8 *data, const u16 data_len)
{
  return NO_ERR;
}

emac_status_t
emac_receive(const u8 channel, emac_frame_t *frame, u16 *data_len)
{
  return NO_ERR;
}

emac_status_t
emac_receive_raw(const u8 channel, u8 *data, u16 *data_len)
{
  return NO_ERR;
}
