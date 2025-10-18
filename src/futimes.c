#include <sys/time.h>

int __iphoneports_futimes(int, const struct timeval *) __asm("_futimes");
int __iphoneports_futimes(int fd, const struct timeval *times) {
  return futimes(fd, times);
}
