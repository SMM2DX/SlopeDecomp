#pragma once

#include "PageBase.hpp"

namespace Lp::UI {
    struct PriorityPage : public PageBase {
		SEAD_RTTI_OVERRIDE(PriorityPage, PageBase)
		~PriorityPage() override;

        virtual void onPostAnimate();
    };
}