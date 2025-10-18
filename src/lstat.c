#include <sys/stat.h>

int __iphoneports_lstat(const char *, struct stat *) __asm("_lstat");
int __iphoneports_lstat(const char *path, struct stat *st) {
  return lstat(path, st);
}
