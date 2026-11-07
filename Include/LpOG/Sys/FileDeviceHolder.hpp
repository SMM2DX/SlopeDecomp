#pragma once

#include <sead/seadDisposer.hpp>
#include <seadOG/thread/seadCriticalSection.h>
#include <seadOG/thread/seadReadWriteLock.h>
#include <seadOG/filedevice/nin/seadNinContentFileDeviceNin.h>
#include <seadOG/filedevice/nin/seadNinAocFileDeviceNin.h>
#include <seadOG/filedevice/nin/seadNinHostIOFileDevice.h>
#include <seadOG/filedevice/nin/seadNinSDFileDeviceNin.h>

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