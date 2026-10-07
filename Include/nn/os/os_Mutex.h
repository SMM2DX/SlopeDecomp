#pragma once

#include "os_MutexTypes.h"
#include "../util.h"

namespace nn::os {

// @nncbindgen
void InitializeMutex(MutexType*, bool recursive, int32_t lockLevel);
// @nncbindgen
void FinalizeMutex(MutexType*);
// @nncbindgen
void LockMutex(MutexType*);
// @nncbindgen
bool TryLockMutex(MutexType*);
// @nncbindgen
void UnlockMutex(MutexType*);

bool IsMutexLockedByCurrentThread(const MutexType*);

class Mutex {
    NN_NO_COPY(Mutex);
    NN_NO_MOVE(Mutex);

public:
    explicit Mutex(bool recursive) { InitializeMutex(&m_Mutex, recursive, 0); }

    Mutex(bool recursive, int32_t lockLevel) { InitializeMutex(&m_Mutex, recursive, lockLevel); }

    ~Mutex() { FinalizeMutex(&m_Mutex); }

    void Lock() { LockMutex(&m_Mutex); }

    bool TryLock() { return TryLockMutex(&m_Mutex); }

    void Unlock() { UnlockMutex(&m_Mutex); }

    bool IsLockedByCurrentThread() const { return IsMutexLockedByCurrentThread(&m_Mutex); }

    void lock() { Lock(); }

    bool try_lock() { return TryLock(); }

    void unlock() { Unlock(); }

    operator MutexType&() { return m_Mutex; }

    operator const MutexType&() const { return m_Mutex; }

    MutexType* GetBase() { return &m_Mutex; }

private:
    MutexType m_Mutex;
};

}  // namespace nn::os
