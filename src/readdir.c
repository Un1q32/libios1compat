#include "dirent.h"
#include <dirent.h>
#include <dlfcn.h>
#include <stdbool.h>
#include <stdlib.h>

struct dirent *readdir(DIR *dir) {
  static bool init = false;
  static struct dirent *(*func)(DIR *);

  if (!init) {
    func = (struct dirent * (*)(DIR *)) dlsym(RTLD_NEXT, "readdir$INODE64");
    init = true;
  }

  if (func)
    return func(dir);

  static struct dirent32 *(*func32)(DIR *) = NULL;
  if (!func32)
    func32 = (struct dirent32 * (*)(DIR *)) dlsym(RTLD_NEXT, "readdir");

  struct dirent32 *ret32 = func32(dir);
  if (!ret32)
    return NULL;
  /* memory leak */
  struct dirent *ret = malloc(sizeof(struct dirent));
  dirent_32_to_64(ret, ret32);
  return ret;
}
