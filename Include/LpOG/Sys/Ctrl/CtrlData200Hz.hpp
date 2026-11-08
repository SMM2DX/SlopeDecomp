#pragma once

#include <oead/math/seadVector.hpp>
#include <oead/math/seadMatrix.hpp>

namespace Lp::Sys {

    struct CtrlData200Hz {
        sead::Vector3f mAcc0;
        sead::Vector3f mAcc1;
        sead::Matrix34f field_18[2];
        sead::Vector3f mGyro0;
        sead::Vector3f mGyro1;
        uint field_90;
        uint field_94;
        uint field_98;
        float field_9C;
        float field_A0;
        float field_A4;
    };

}