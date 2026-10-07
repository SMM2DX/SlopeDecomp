#pragma once

#include <cstddef>
#include "bcat/bcat_Util.h"

namespace nn::bcat {

class DeliveryCacheFile {
public:
    DeliveryCacheFile();
    ~DeliveryCacheFile();
    Result Open(DirectoryName const&, FileName const&);
    Result Read(size_t file1, int64_t, void*, size_t file2);
    Result GetSize();
    Result GetDigest();
    Result Close();
};

}  // namespace nn::bcat
