#include <sys/stat.h>

int __iphoneports_lstatx_np(const char *, struct stat *,
                            filesec_t) __asm("_lstatx_np");
int __iphoneports_lstatx_np(const char *path, struct stat *st,
                            filesec_t filesec) {
  return lstatx_np(path, st, filesec);
}
