/**
 * @file os.h
 * @brief Operating System implementations.
 */

#pragma once

#include <type_traits>

#include "time.h"

#include "os/detail/os_InternalCriticalSection.h"
#include "os/os_Event.h"
#include "os/os_MessageQueue.h"
#include "os/os_Mutex.h"
#include "os/os_MutexTypes.h"
#include "os/os_ThreadCommon.h"
#include "os/os_ThreadTypes.h"
#include "os/os_TickTypes.h"

namespace nn::os {

namespace detail {

struct InterProcessEventType {
    enum State {
        State_NotInitialized = 0,
        State_Initialized = 1,
    };

    nn::os::detail::InterProcessEventType* _x0;
    nn::os::detail::InterProcessEventType* _x8;
    bool shouldAutoClear;
    uint8_t state;
    bool isReadableHandleManaged;
    bool isWritableHandleManaged;
    uint32_t readableHandle;
    uint32_t writableHandle;
};
}  // namespace detail

struct LightEventType {
    std::aligned_storage_t<0xc, 4> storage;
};

struct ConditionVariableType {};

struct SemaphoreType {
    std::aligned_storage_t<0x28, 8> storage;
};

struct SystemEventType {
    enum State {
        State_NotInitialized = 0,
        State_InitializedAsEvent = 1,
        State_InitializedAsInterProcessEvent = 2,
    };

    union {
        nn::os::EventType event;
        nn::os::detail::InterProcessEventType interProcessEvent;
    };
    uint8_t state;
};
struct SystemEvent {
    SystemEventType m_SystemEventType;
};

// ARG
void SetHostArgc(int32_t);
int32_t GetHostArgc();
void SetHostArgv(char**);
char** GetHostArgv();

// MEMORY
void InitializeVirtualAddressMemory();
Result AllocateAddressRegion(uint64_t*, uint64_t);
Result AllocateMemory(uint64_t*, uint64_t);
Result AllocateMemoryPages(uint64_t, uint64_t);
void AllocateMemoryBlock(uint64_t*, uint64_t);
void FreeMemoryBlock(uint64_t, uint64_t);
void SetMemoryHeapSize(uint64_t);

// CONDITION VARIABLE
void InitializeConditionVariable(ConditionVariableType*);
void FinalizeConditionVariable(ConditionVariableType*);

void SignalConditionVariable(ConditionVariableType*);
void BroadcastConditionVariable(ConditionVariableType*);
void WaitConditionVariable(ConditionVariableType*);
uint8_t TimedWaitConditionVariable(ConditionVariableType*, nn::os::MutexType*, nn::TimeSpan);

// THREAD
Result CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg, void* srcStack,
                    uint64_t stackSize, int32_t priority, int32_t coreNum);
Result CreateThread(nn::os::ThreadType*, void (*)(void*), void* arg, void* srcStack,
                    uint64_t stackSize, int32_t priority);
void DestroyThread(nn::os::ThreadType*);
void StartThread(nn::os::ThreadType*);
void SetThreadName(nn::os::ThreadType*, char const* threadName);
void SetThreadNamePointer(nn::os::ThreadType*, char const*);
char* GetThreadNamePointer(nn::os::ThreadType const*);
nn::os::ThreadType* GetCurrentThread();
void GetCurrentStackInfo(uintptr_t* stack_addr, size_t* stack_size);
int32_t ChangeThreadPriority(nn::os::ThreadType* thread, int32_t priority);
int32_t GetThreadPriority(nn::os::ThreadType const* thread);
uint64_t GetThreadId(const nn::os::ThreadType* thread);
void YieldThread();
void SuspendThread(nn::os::ThreadType*);
void ResumeThread(nn::os::ThreadType*);
void SleepThread(nn::TimeSpan);
void WaitThread(nn::os::ThreadType*);
void SetThreadCoreMask(nn::os::ThreadType*, int, uint64_t mask);

// LIGHT EVENTS
void InitializeLightEvent(LightEventType*, bool initiallySignaled, EventClearMode eventClearMode);
void FinalizeLightEvent(LightEventType*);
void SignalLightEvent(LightEventType*);
void WaitLightEvent(LightEventType*);
bool TimedWaitLightEvent(LightEventType*, nn::TimeSpan);
void ClearLightEvent(LightEventType*);

// SEMAPHORES
void InitializeSemaphore(SemaphoreType* semaphore, int32_t initial_count, int32_t max_count);
void FinalizeSemaphore(SemaphoreType* semaphore);
void AcquireSemaphore(SemaphoreType* semaphore);
bool TryAcquireSemaphore(SemaphoreType* semaphore);
void ReleaseSemaphore(SemaphoreType* semaphore);

// EXCEPTION HANDLING
typedef union {
    uint64_t x;  ///< 64-bit AArch64 register view.
    uint32_t w;  ///< 32-bit AArch64 register view.
    uint32_t r;  ///< AArch32 register view.
} CpuRegister;
/// Armv8 NEON register.

typedef union {
    __uint128_t v;  ///< 128-bit vector view.
    double d;       ///< 64-bit double-precision view.
    float s;        ///< 32-bit single-precision view.
} FpuRegister;

struct UserExceptionInfo {
    uint32_t ErrorDescription;  ///< See \ref ThreadExceptionDesc.
    uint32_t pad[3];

    CpuRegister CpuRegisters[29];  ///< GPRs 0..28. Note: also contains AArch32 registers.
    CpuRegister FP;                ///< Frame pointer.
    CpuRegister LR;                ///< Link register.
    CpuRegister SP;                ///< Stack pointer.
    CpuRegister PC;                ///< Program counter (elr_el1).

    uint64_t padding;

    FpuRegister FpuRegisters[32];  ///< 32 general-purpose NEON registers.

    uint32_t PState;  ///< pstate & 0xFF0FFE20
    uint32_t AFSR0;
    uint32_t AFSR1;
    uint32_t ESR;

    CpuRegister FAR;  ///< Fault Address Register.
};
void SetUserExceptionHandler(void (*)(UserExceptionInfo*), void*, size_t, UserExceptionInfo*);

// OTHER
void GenerateRandomBytes(void*, uint64_t);
uint64_t GetThreadAvailableCoreMask();

// Thread-local storage
struct TlsSlot {
    uint32_t slot;
};
Result AllocateTlsSlot(TlsSlot* slot_out, void (*)(uint64_t));
void FreeTlsSlot(TlsSlot slot);
uint64_t GetTlsValue(TlsSlot slot);
void SetTlsValue(TlsSlot slot, uint64_t value);
uint32_t GetCurrentCoreNumber();

namespace detail {
extern int32_t g_CommandLineParameter;
extern char** g_CommandLineParameterArgv;
}  // namespace detail
}  // namespace nn::os
