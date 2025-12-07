#include "../include/emac.h"
#include "../include/fw_protocol.h"

static u32     __fwproto_timeout_ms = 0;
static u8      __fwproto_channel    = 0;
static boolean __fwproto_connected  = FALSE;

void
fwproto_set_timeout_for_all(const u32 timeout_ms)
{
  __fwproto_timeout_ms = timeout_ms;
}

fwproto_status_t
fwproto_init(const u8 channel)
{
  /// @todo Обработать ошибку
  if (__fwproto_connected) { return NO_ERR; }

  __fwproto_channel = channel;
  emac_status_t st  = emac_init(channel, NULL);

  return (st == NO_ERR) ? NO_ERR : st;
}

fwproto_status_t
fwproto_wait_conn()
{
  if (__fwproto_connected) { return NO_ERR; }
  return NO_ERR;
}

fwproto_status_t
fwproto_conn()
{
  if (__fwproto_connected) { return NO_ERR; }
  return NO_ERR;
}

fwproto_status_t
fwproto_wait_close()
{
  if (!__fwproto_connected) { return NO_ERR; }
  return NO_ERR;
}

fwproto_status_t
fwproto_close()
{
  if (!__fwproto_connected) { return NO_ERR; }
  return NO_ERR;
}

fwproto_status_t
fwproto_send(const fwproto_packet_t *packet, const u16 len)
{
  if (!__fwproto_connected) { return FW_ERR_CONNECTION; }
  return NO_ERR;
}

fwproto_status_t
fwproto_receive(fwproto_packet_t *packet, u16 *len)
{
  if (!__fwproto_connected) { return FW_ERR_CONNECTION; }
  return NO_ERR;
}

fwproto_status_t
fwproto_get_cfg_packet(fwproto_cfg_packet_t *cfg_packet, u16 *chunks_len)
{
  if (!__fwproto_connected) { return FW_ERR_CONNECTION; }
  return NO_ERR;
}
