#pragma once

#include "PageBase.hpp"
#include "../../sead/hostio/seadHostIOEventListener.h"
#include "../../sead/hostio/seadHostIOReflexible.h"

namespace Lp::UI {
    struct Page : public PageBase {
		SEAD_RTTI_OVERRIDE(Page, PageBase)
		~Page() override;

	    virtual void genMessage(sead::hostio::Context*);
	    virtual void listenPropertyEvent(sead::hostio::PropertyEvent const*);
	    virtual void onPostAnimate();
    };
}