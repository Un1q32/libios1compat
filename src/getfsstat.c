#include "statfs.h"
#include <dlfcn.h>
#include <stdbool.h>
#include <stdlib.h>

int getfsstat(struct statfs *buf, int bufsize, int flags) {
  static bool init = false;
  static int (*func)(struct statfs *, int, int);

  if (!init) {
    func = (int (*)(struct statfs *, int, int))dlsym(RTLD_NEXT,
                                                     "getfsstat$INODE64");
    init = true;
  }

  if (func)
    return func(buf, bufsize, flags);

  static int (*func32)(struct statfs32 *, int, int) = NULL;
  if (!func32)
    func32 =
        (int (*)(struct statfs32 *, int, int))dlsym(RTLD_NEXT, "getfsstat");

  int buf32size = bufsize / sizeof(struct statfs);
  void *buf32 = malloc(buf32size * sizeof(struct statfs32));
  int ret = func32(buf32, buf32size * sizeof(struct statfs32), flags);
  while (buf32size--)
    statfs_32_to_64(buf + buf32size, buf32 + buf32size);
  return ret;
}
