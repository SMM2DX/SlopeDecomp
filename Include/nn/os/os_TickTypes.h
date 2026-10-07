#pragma once

#include "../nn_TimeSpan.h"
#include "../util.h"

namespace nn::os {

class Tick;

Tick GetSystemTick();
Tick GetSystemTickFrequency();
Tick ConvertToTick(nn::TimeSpan timeSpan);
nn::TimeSpan ConvertToTimeSpan(Tick ticks);

// @nncbindgen typedef int64_t
class Tick {
public:
    Tick() = default;

    Tick(int64_t tick) : m_Tick(tick) {}

    Tick(TimeSpan timeSpan) : m_Tick(ConvertToTick(timeSpan).GetInt64Value()) {}

    int64_t GetInt64Value() const { return m_Tick; }

    TimeSpan ToTimeSpan() const { return ConvertToTimeSpan(*this); }

    Tick& operator-=(Tick rhs) {
        m_Tick -= rhs.m_Tick;
        return *this;
    }

    Tick operator-(Tick rhs) const {
        Tick ret{*this};
        return ret -= rhs;
    }

    Tick& operator+=(Tick rhs) {
        m_Tick += rhs.m_Tick;
        return *this;
    }

    Tick operator+(Tick rhs) const {
        Tick ret{*this};
        return ret += rhs;
    }

private:
    int64_t m_Tick;
};

}  // namespace nn::os
