#pragma once

#include <sead/seadDisposer.hpp>
#include <OLD/sead/thread/seadCriticalSection.h>
#include <OLD/sead/thread/seadReadWriteLock.h>
#include <OLD/sead/filedevice/nin/seadNinContentFileDeviceNin.h>
#include <OLD/sead/filedevice/nin/seadNinAocFileDeviceNin.h>
#include <OLD/sead/filedevice/nin/seadNinHostIOFileDevice.h>
#include <OLD/sead/filedevice/nin/seadNinSDFileDeviceNin.h>

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