#pragma once

#include <sead/seadDisposer.hpp>
#include "hostio/seadHostIONode.h"
#include <sead/seadSafeString.hpp>

namespace sead
{
class GameConfig : public hostio::Node
{
    SEAD_SINGLETON_DISPOSER(GameConfig)
    GameConfig();
    virtual ~GameConfig();

    static const SafeString cNodeName;

protected:
    struct FileWriteCallback
    {
        virtual ~FileWriteCallback();
        virtual void save();
    };
};
}  // namespace sead
