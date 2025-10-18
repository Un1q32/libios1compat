#include <sys/stat.h>

int __iphoneports_stat(const char *, struct stat *) __asm("_stat");
int __iphoneports_stat(const char *path, struct stat *st) {
  return stat(path, st);
}
