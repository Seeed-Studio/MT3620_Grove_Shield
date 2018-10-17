#pragma once
#include <time.h>
#include <stdbool.h>

/// <summary>
///     Compare two timespecs, returning true if the fist timespec is
///     greater than the second.
/// </summary>
/// <param name="s">Pointer to the first timespec.</param>
/// <param name="t">Pointer to the second timespe.c</param>
/// <returns>True if the first timespec is greater than the second; otherwise, false.</returns>
bool TimerUtility_TimerCompareGreater(const struct timespec *s, const struct timespec *t);

/// <summary>
///     Compare two timespecs, returning true if the fist timespec is
///     less than or equal to the second.
/// </summary>
/// <param name="s">Pointer to the first timespec.</param>
/// <param name="t">Pointer to the second timespec.</param>
/// <returns>
///     True if the first timespec is less than or equal to the second; otherwise,
///     false.
/// </returns>
bool TimerUtility_TimerCompareLesserEqual(const struct timespec *s, const struct timespec *t);
/// <summary>
///     Compare two timespecs, returning true if the fist timespec is
///     exactly equal to the second.
/// </summary>
/// <param name="s">Pointer to the first timespec.</param>
/// <param name="t">Pointer to the second timespec.</param>
/// <returns>True if the first timespec is exactly equal to the second; otherwise, false.</returns>
bool TimerUtility_TimerEqual(const struct timespec *s, const struct timespec *t);

/// <summary>
///     Add two timespecs.
/// </summary>
/// <param name="s">Pointer to he first timespec.</param>
/// <param name="t">Pointer to the second timespec.</param>
/// <param name="a">Pointer to a timespec to hold the result.</param>
void TimerUtility_TimerAdd(const struct timespec *s, const struct timespec *t, struct timespec *a);
