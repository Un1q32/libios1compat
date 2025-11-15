#ifndef _IOS1COMPAT_DIRENT_H_
#define _IOS1COMPAT_DIRENT_H_

#include <stdint.h>
#include <string.h>
#include <sys/dirent.h>

#pragma pack(4)

struct dirent32 {
  uint32_t d_ino;
  uint16_t d_reclen;
  uint8_t d_type;
  uint8_t d_namlen;
  char d_name[256];
};

#pragma pack()

static inline void dirent_32_to_64(struct dirent *out, struct dirent32 *in) {
  out->d_ino = in->d_ino;
  out->d_reclen = in->d_reclen;
  out->d_type = in->d_type;
  out->d_namlen = in->d_namlen;
  out->d_seekoff = 0;
  memcpy(out->d_name, in->d_name, 256);
}

#endif
