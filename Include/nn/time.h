#pragma once

#include <cstdint>
#include "nn_Result.h"
#include "nn_TimeSpan.h"

namespace nn::time {

Result Initialize();
bool IsInitialized();

struct CalendarTime {
    int16_t year;
    int8_t month;
    int8_t day;
    int8_t hour;
    int8_t minute;
    int8_t second;
};

enum DayOfTheWeek { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

struct TimeZone {
    char standardTimeName[0x8];
    bool _9;            // daylight savings or something?
    int32_t utcOffset;  // in seconds
};

struct CalendarAdditionalInfo {
    nn::time::DayOfTheWeek dayOfTheWeek;
    int32_t dayofYear;
    nn::time::TimeZone timeZone;
};

struct PosixTime {
    uint64_t time;
};

class StandardUserSystemClock {
public:
    static Result GetCurrentTime(nn::time::PosixTime*);
};

struct TimeZoneRule;  // shrug

Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
                      nn::time::PosixTime const&);
Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
                      nn::time::PosixTime const&, nn::time::TimeZoneRule const&);
Result ToPosixTime(int*, PosixTime*, int, const CalendarTime&);
CalendarTime ToCalendarTimeInUtc(const PosixTime&);
PosixTime ToPosixTimeFromUtc(const CalendarTime&);
}  // namespace nn::time
