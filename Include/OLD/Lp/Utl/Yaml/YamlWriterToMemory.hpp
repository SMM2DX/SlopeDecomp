#pragma once

#include <OLD/sead/stream/seadStream.h>
#include <OLD/sead/stream/seadRamStream.h>

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