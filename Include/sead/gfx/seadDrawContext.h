#pragma once

//#include "../../nn/gfx/gfx_CommandBuffer.h" TEMP
//#include "../../nn/gfx/gfx_Types.h" TEMP
#include "../basis/seadTypes.h"
#include "../prim/seadRuntimeTypeInfo.h"

namespace sead
{
class DrawContext
{
    SEAD_RTTI_BASE(DrawContext)
public:
    DrawContext();
    virtual ~DrawContext();

    //nn::gfx::CommandBuffer* getCommandBuffer() { return &mCommandBuffer; } TEMP

private:
    //nn::gfx::CommandBuffer mCommandBuffer; TEMP
};
//static_assert(sizeof(DrawContext) == 0xF0); TEMP

}  // namespace sead
