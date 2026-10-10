#pragma once

//#include <agl/lyr/DrawMethod.hpp> TEMP
#include "../../../sead/framework/seadCalculateTask.h"
#include "../../../sead/framework/seadMethodTree.h"

namespace agl::lyr {
    struct RenderInfo;
}

namespace Lp::Sys {
    struct ProjTaskBase : public sead::CalculateTask {
        SEAD_RTTI_OVERRIDE(ProjTaskBase, sead::CalculateTask)
    
        //agl::lyr::DrawMethod m2DRenderMethod; TEMP
        //agl::lyr::DrawMethod m3DRenderMethod; TEMP
        
        virtual void draw2D(agl::lyr::RenderInfo const&);
        virtual void draw3D(agl::lyr::RenderInfo const&);
    };
    //static_assert(sizeof(ProjTaskBase) == 0x228, ""); TEMP
}