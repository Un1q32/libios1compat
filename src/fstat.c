#include <sys/stat.h>

int __iphoneports_fstat(int, struct stat *) __asm("_fstat");
int __iphoneports_fstat(int fd, struct stat *st) { return fstat(fd, st); }
