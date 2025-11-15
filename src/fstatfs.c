#include "statfs.h"
#include <dlfcn.h>
#include <stdbool.h>

int fstatfs(int fd, struct statfs *buf) {
  static bool init = false;
  static int (*func)(int, struct statfs *);

  if (!init) {
    func = (int (*)(int, struct statfs *))dlsym(RTLD_NEXT, "fstatfs$INODE64");
    init = true;
  }

  if (func)
    return func(fd, buf);

  static int (*func32)(int, struct statfs32 *) = NULL;
  if (!func32)
    func32 = (int (*)(int, struct statfs32 *))dlsym(RTLD_NEXT, "fstatfs");

  struct statfs32 buf32;
  int ret = func32(fd, &buf32);
  statfs_32_to_64(buf, &buf32);
  return ret;
}
