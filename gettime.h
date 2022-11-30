#include <sys/time.h>

#define WEAK_IMPORT __attribute__((weak_import))

int gettime(int clock_id, struct timespec *ts);
