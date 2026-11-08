#pragma once

#include <sead/seadDisposer.hpp>
#include <oead/thread/seadCriticalSection.h>
#include <oead/thread/seadReadWriteLock.h>
#include <oead/filedevice/nin/seadNinContentFileDeviceNin.h>
#include <oead/filedevice/nin/seadNinAocFileDeviceNin.h>
#include <oead/filedevice/nin/seadNinHostIOFileDevice.h>
#include <oead/filedevice/nin/seadNinSDFileDeviceNin.h>

namespace Lp::Sys {
    struct FileDeviceHolder {
        /* TODO: where does this come from? */
        uintptr_t field_8;
        sead::CriticalSection mCS;
        sead::ReadWriteLock mRWLock;
        SEAD_SINGLETON_DISPOSER(FileDeviceHolder);
        public:
        sead::NinContentFileDevice* mContent;
        sead::NinAocFileDevice* mAoc;
        sead::NinHostIOFileDevice* mDialog; /* Lp::Sys::DialogFileDevice* */
        sead::NinSDFileDevice* mSD;

        virtual ~FileDeviceHolder();
    };
}