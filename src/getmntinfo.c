#include "statfs.h"
#include <dlfcn.h>
#include <stdbool.h>
#include <stdlib.h>

int getmntinfo(struct statfs **bufp, int mode) {
  static bool init = false;
  static int (*func)(struct statfs **, int);

  if (!init) {
    func =
        (int (*)(struct statfs **, int))dlsym(RTLD_NEXT, "getmntinfo$INODE64");
    init = true;
  }

  if (func)
    return func(bufp, mode);

  static int (*func32)(struct statfs32 **, int) = NULL;
  if (!func32)
    func32 = (int (*)(struct statfs32 **, int))dlsym(RTLD_NEXT, "getmntinfo");

  // int ret = func32(buf32p, mode);
  // return ret;
  abort();
}
