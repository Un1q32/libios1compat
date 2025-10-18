#include <sys/stat.h>

int __iphoneports_statx_np(const char *, struct stat *,
                           filesec_t) __asm("_statx_np");
int __iphoneports_statx_np(const char *path, struct stat *st,
                           filesec_t filesec) {
  return statx_np(path, st, filesec);
}
