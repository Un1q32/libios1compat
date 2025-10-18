#include <bsm/audit.h>

int __iphoneports_setaudit(const struct auditinfo *) __asm("_setaudit");
int __iphoneports_setaudit(const struct auditinfo *info) {
  return setaudit(info);
}
