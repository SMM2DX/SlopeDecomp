#pragma once

#include <oead/stream/seadStream.h>
#include <oead/stream/seadRamStream.h>

#include "YamlFormatter.hpp"

namespace Lp::Utl {
    struct YamlWriterToMemory : public YamlFormatter {
        uchar* mBuffer;
        uint mBufferSize;
        sead::RamWriteStream mStream;

        virtual ~YamlWriterToMemory();
        uint getUsedBufferSize() const;   
    };
}