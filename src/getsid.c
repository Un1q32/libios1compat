#include <unistd.h>

pid_t __iphoneports_getsid(pid_t) __asm("_getsid");
pid_t __iphoneports_getsid(pid_t pid) { return getsid(pid); }
