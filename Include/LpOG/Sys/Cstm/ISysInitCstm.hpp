#pragma once

#include <oead/framework/nx/seadGameFrameworkNx.h>
#include <oead/math/seadVector.hpp>
#include <oead/heap/seadHeap.h>

namespace Lp::Sys {

    struct ISysInitCstm {
        SEAD_RTTI_BASE(ISysInitCstm);

        public:
        virtual void setHeapInfo();
        virtual void overwriteFrameworkCreateArg(sead::GameFrameworkNx::CreateArg*);
        virtual size_t getRootTaskPrepareThreadStackSize() const;
        virtual void setRootTaskCstm();
        virtual void onAppExit();
        virtual sead::Vector2<int> getScanBufferSize() const;
        virtual sead::Vector2f getVirtualCanvasSize();

        static ISysInitCstm* spCstm;
    };

}