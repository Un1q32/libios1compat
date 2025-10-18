#include <bsm/audit.h>

pid_t __iphoneports_setaudit_addr(const struct auditinfo_addr *,
                                  int) __asm("_setaudit_addr");
pid_t __iphoneports_setaudit_addr(const struct auditinfo_addr *addr, int len) {
  return setaudit_addr(addr, len);
}
