#pragma once

#include "bcat/bcat_Util.h"
#include "nn_Result.h"

namespace nn::bcat {

class DeliveryCacheDirectory {
public:
    DeliveryCacheDirectory();
    ~DeliveryCacheDirectory();
    Result Open(DirectoryName const&);
    Result GetCount();
    Result Close();
};

}  // namespace nn::bcat
