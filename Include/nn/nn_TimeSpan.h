#pragma once

#include <cstdint>

namespace nn {

// @nncbindgen typedef int64_t
class TimeSpan {
public:
    int64_t nanoseconds;

    static TimeSpan FromNanoSeconds(int64_t nanoSeconds) {
        TimeSpan ret;
        ret.nanoseconds = nanoSeconds;
        return ret;
    }
    static TimeSpan FromMilliSeconds(int64_t milliseconds) {
        return FromNanoSeconds(milliseconds * 1000 * 1000);
    }
    static TimeSpan FromSeconds(int64_t seconds) {
        return FromNanoSeconds(seconds * 1000 * 1000 * 1000);
    }
    static TimeSpan FromMinutes(int64_t minutes) {
        return FromNanoSeconds(minutes * 1000 * 1000 * 1000 * 60);
    }
    static TimeSpan FromHours(int64_t hours) {
        return FromNanoSeconds(hours * 1000 * 1000 * 1000 * 60 * 60);
    }
    static TimeSpan FromDays(int64_t days) {
        return FromNanoSeconds(days * 1000 * 1000 * 1000 * 60 * 60 * 24);
    }
};

}  // namespace nn
