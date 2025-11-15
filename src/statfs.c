#include "statfs.h"
#include <dlfcn.h>
#include <stdbool.h>

int statfs(const char *path, struct statfs *buf) {
  static bool init = false;
  static int (*func)(const char *, struct statfs *);

  if (!init) {
    func = (int (*)(const char *, struct statfs *))dlsym(RTLD_NEXT,
                                                         "statfs$INODE64");
    init = true;
  }

  if (func)
    return func(path, buf);

  static int (*func32)(const char *, struct statfs32 *) = NULL;
  if (!func32)
    func32 =
        (int (*)(const char *, struct statfs32 *))dlsym(RTLD_NEXT, "statfs");

  struct statfs32 buf32;
  int ret = func32(path, &buf32);
  statfs_32_to_64(buf, &buf32);
  return ret;
}
