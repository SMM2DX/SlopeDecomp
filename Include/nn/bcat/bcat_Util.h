#pragma once

#include "nn_Result.h"

namespace nn::bcat {

struct FileName {
    void isValid();
};

struct DirectoryName {
    void isValid();
};

Result Initialize();

}  // namespace nn::bcat
