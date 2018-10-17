#include "timer_utility.h"

// Time function utilities.
bool TimerUtility_TimerCompareGreater(const struct timespec *s, const struct timespec *t)
{
    return (s->tv_sec == t->tv_sec) ? (s->tv_nsec > t->tv_nsec) : (s->tv_sec) > (t->tv_sec);
}

bool TimerUtility_TimerCompareLesserEqual(const struct timespec *s, const struct timespec *t)
{
    return (s->tv_sec == t->tv_sec) ? (s->tv_nsec <= t->tv_nsec) : (s->tv_sec) <= (t->tv_sec);
}

bool TimerUtility_TimerEqual(const struct timespec *s, const struct timespec *t)
{
    return (s->tv_nsec == t->tv_nsec) && (s->tv_sec == t->tv_sec);
}

void TimerUtility_TimerAdd(const struct timespec *s, const struct timespec *t, struct timespec *a)
{
    a->tv_sec = s->tv_sec + t->tv_sec;
    if ((a->tv_nsec = s->tv_nsec + t->tv_nsec) >= 1000000000) {
        a->tv_nsec -= 1000000000;
        a->tv_sec++;
    }
}
