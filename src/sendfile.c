#include <sys/socket.h>

int __iphoneports_sendfile(int, int, off_t, off_t *, struct sf_hdtr *,
                           int) __asm("_sendfile");
int __iphoneports_sendfile(int fd, int s, off_t offset, off_t *len,
                           struct sf_hdtr *hdtr, int flags) {
  return sendfile(fd, s, offset, len, hdtr, flags);
}
