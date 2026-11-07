#pragma once

#include <sead/seadListImpl.hpp>
#include "../Impl/Observer.hpp"
#include "TypeInfo.hpp"
#include "ContentBase.hpp"

namespace Lp::UI {
    struct ValueBase : public ContentBase {
        sead::OffsetList<Impl::Observer> mObservers;

        virtual ~ValueBase();
        void setVirtual(TypeInfo const&, void const*);
        void* getAsPtrVirtual(TypeInfo const&, void*) const;
        Lp::UI::ValueBase* clone() const;
    };
}