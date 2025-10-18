#include <sys/stat.h>

int __iphoneports_fstatx_np(int, struct stat *, filesec_t) __asm("_fstatx_np");
int __iphoneports_fstatx_np(int fd, struct stat *st, filesec_t filesec) {
  return fstatx_np(fd, st, filesec);
}
