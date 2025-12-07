#include "../include/fimware.h"

static inline void
__fw_icache(fw_image_t *fw)
{
}

static inline void
__fw_dcache(fw_image_t *fw)
{
}

fw_status_t
fw_init(fw_image_t *fw)
{
  return NO_ERR;
}

fw_status_t
fw_append(fw_image_t *fw, u8 *data, usize len)
{
  // append new data and then icache, dcache
  __fw_icache(fw);
  __fw_dcache(fw);
  return NO_ERR;
}

fw_status_t
fw_finalize(fw_image_t *fw)
{
  return NO_ERR;
}

fw_status_t
fw_jump(fw_image_t *fw)
{
  return NO_ERR;
}
