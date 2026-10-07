#pragma once

namespace nn::sf {

template <typename A, typename B>
class Out {
public:
    constexpr Out(A& p) : data{&p} {}
    constexpr A& GetData() { return *data; };

    A* data;
};

}  // namespace nn::sf
