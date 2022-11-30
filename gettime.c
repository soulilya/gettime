#include <sys/time.h>
#include <mach/clock.h>
#include <mach/mach.h>

#include "gettime.h"


int gettime(int clock_id, struct timespec *ts) {
    if(clock_id == 0) {
        struct timeval now;
        int rv = gettimeofday(&now, NULL);
        if (rv) return rv;
        ts->tv_sec  = now.tv_sec;
        ts->tv_nsec = now.tv_usec * 1000;
        return rv;
    } else {
        clock_serv_t cclock;
        mach_timespec_t mts;
        host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
        clock_get_time(cclock, &mts);
        mach_port_deallocate(mach_task_self(), cclock);
        ts->tv_sec = mts.tv_sec;
        ts->tv_nsec = mts.tv_nsec;
        return 0;
    }
    return 0;
}
