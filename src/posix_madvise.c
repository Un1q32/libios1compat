#include <sys/mman.h>

int __iphoneports_posix_madvise(void *, size_t, int) __asm("_posix_madvise");
int __iphoneports_posix_madvise(void *addr, size_t size, int advice) {
  return posix_madvise(addr, size, advice);
}
