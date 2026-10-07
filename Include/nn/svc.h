#pragma once

#include <cstddef>
#include <cstdint>
#include "nn_Result.h"
#include "util.h"

namespace nn::svc {

#ifdef __aarch64__
#define aarch aarch64
#define lp lp64
#define svc_instruction "svc"
#else
#ifdef __arm__
#define aarch aarch32
#define lp ilp32
#define svc_instruction "swi"
#else
#error Unsupported Architecture
#endif
#endif

struct Handle {
    uint32_t handle;

    Handle(uint32_t h) { handle = h; }

    Handle() : Handle(0) {}

    operator uint32_t() const { return handle; }
};

enum class MemoryPermission { Read = 1 << 0, Write = 1 << 1, Execute = 1 << 2, DontCare = 1 << 28 };

enum class MemoryType {
    Free,
    Io,
    Static,
    Code,
    CodeData,
    Normal,
    Shared,
    Alias,
    AliasCode,
    AliasCodeData,
    Ipc,
    Stack,
    ThreadLocal,
    Transferred,
    SharedTransferred,
    SharedCode,
    Inaccessible,
    NonSecureIpc,
    NonDeviceIpc,
    Kernel,
    GeneratedCode,
    CodeOut,
    Coverage,
    Insecure,
};

enum class MemoryAttribute {
    Locked = 1 << 0,
    IpcLocked = 1 << 1,
    DeviceShared = 1 << 2,
    Uncached = 1 << 3,
    PermissionLocked = 1 << 4,
    GpuSharable = 1 << 5,
    GpuShared = 1 << 6,
};

struct PageInfo {};  // TODO

enum class BreakReason {};  // TODO

enum class InfoType {
    CoreMask,
    PriorityMask,
    AliasRegionAddress,
    AliasRegionSize,
    HeapRegionAddress,
    HeapRegionSize,
    TotalMemorySize,
    UsedMemorySize,
    DebuggerAttached,
    ResourceLimit,
    IdleTickCount,
    RandomEntropy,
    AslrRegionAddress,
    AslrRegionSize,
    StackRegionAddress,
    StackRegionSize,
    SystemResourceSizeTotal,
    SystemResourceSizeUsed,
    ProgramId,
    InitialProcessIdRange,
    UserExceptionContextAddress,
    TotalNonSystemMemorySize,
    UsedNonSystemMemorySize,
    IsApplication,
    FreeThreadCount,
    ThreadTickCount,
    IsSvcPermitted,
    IoRegionHint,
    AliasRegionExtraSize,
    RemoteRegionAddress,
    RemoteRegionSize,
    RemoteMemoryUsage,
    RemoteMemoryUsagePeak,
    ProcessPageSize,
    TransferMemoryHint,
};

enum class LimitableResource {
    PhysicalMemoryMax,
    ThreadCountMax,
    EventCountMax,
    TransferMemoryCountMax,
    SessionCountMax,
};

enum class ThreadActivity { None, Runnable };

enum class ProcessActivity { None, Runnable };

struct ThreadContext {
    int8_t padding[0xe8];
};  // TODO

enum class DumpInfoType {};  // TODO

struct InterruptEvent {};  // TODO

enum class InterruptEventType {};  // TODO

enum class DeviceName {
    AFI,
    AVPC,
    DC,
    DCB,
    HC,
    HDA,
    ISP2,
    MSENCNVENC,
    NV,
    NV2,
    PPCS,
    SATA,
    VI,
    VIC,
    XUSB_HOST,
    XUSB_DEV,
    TSEC,
    PPCS1,
    DC1,
    SDMMC1A,
    SDMMC2A,
    SDMMC3A,
    SDMMC4A,
    ISP2B,
    GPU,
    GPUB,
    PPCS2,
    NVDEC,
    APE,
    SE,
    NVJPG,
    HC1,
    SE1,
    AXIAP,
    ETR,
    TSECB,
    TSEC1,
    TSECB1,
    NVDEC1,
};

enum class HardwareBreakPointRegisterName {};  // TODO

enum class DebugThreadParam {
    DynamicPriority,
    SchedulingStatus,
    PreferredCpuCore,
    CurrentCpuCore,
    AffinityMask,
};

enum class ProcessInfoType { ProcessState };

namespace lp {
struct MemoryInfo {
    uintptr_t baseAddress;
    size_t size;
    MemoryType memoryType;
    MemoryAttribute memoryAttribute;
    MemoryPermission memoryPermission;
    int32_t ipcRefCount;
    int32_t deviceRefCount;
};

struct LastThreadContext {
    uint64_t _0;
    uint64_t _8;
    uint64_t _10;
    uint64_t _18;
};  // TODO

struct PhysicalMemoryInfo {
    uint64_t _0;
    uint64_t _8;
    uint64_t _10;
};  // TODO

struct DebugEventInfo {
    char padding[0x40];
};  // TODO

struct CreateProcessParameter {
    char _0[0xc];
    int32_t _c;
    int64_t _10;
    uint64_t _18;
    int32_t _20;
    int32_t _24;
    Handle _28;
    int32_t _2c;
};  // TODO

}  // namespace lp

// NOLINTNEXTLINE(modernize-concat-nested-namespaces) need aarch to exist
namespace aarch {
#ifdef __aarch64__
namespace lp {
#endif

Result SetHeapSize(uintptr_t* outHeapAddress, size_t heapSize);
Result SetMemoryPermission(uintptr_t address, size_t regionSize, MemoryPermission memoryPermission);
Result SetMemoryAttribute(uintptr_t address, size_t size, uint32_t mask, uint32_t attr);
Result MapMemory(uintptr_t dstAddress, uintptr_t srcAddress, size_t size);
Result UnmapMemory(uintptr_t dstAddress, uintptr_t srcAddress, size_t size);
Result QueryMemory(svc::lp::MemoryInfo* outMemoryInfo, PageInfo* outPageInfo, uintptr_t address);
void ExitProcess();
Result CreateThread(Handle* outHandle, uintptr_t entryPointAddress, uintptr_t threadContextAddress,
                    uintptr_t stackAddress, int32_t priority, int32_t coreId);
Result StartThread(Handle Handle);
void ExitThread();
void SleepThread(int64_t ns);
Result GetThreadPriority(int32_t* outPriority, Handle handle);
Result SetThreadPriority(Handle handle, int32_t priority);
Result GetThreadCoreMask(int32_t* outCoreId, uint64_t* outAffinityMask, Handle handle);
Result SetThreadCoreMask(Handle handle, int32_t coreId, uint64_t affinityMask);
int32_t GetCurrentProcessorNumber();
Result SignalEvent(Handle handle);
Result ClearEvent(Handle handle);
Result MapSharedMemory(Handle handle, uintptr_t address, size_t size,
                       MemoryPermission memoryPermission);
Result UnmapSharedMemory(Handle handle, uintptr_t address, size_t size);
Result CreateTransferMemory(Handle* outHandle, uintptr_t address, size_t size,
                            MemoryPermission memoryPermission);
Result CloseHandle(Handle handle);
Result ResetSignal(Handle handle);
Result WaitSynchronization(int32_t* outHandleIndex, const Handle* handles, int32_t handleCount,
                           int64_t timeoutNs);
Result CancelSynchronization(Handle handle);
Result ArbitrateLock(Handle handle, uintptr_t address, uint32_t tag);
Result ArbitrateUnlock(uintptr_t address);
Result WaitProcessWideKeyAtomic(uintptr_t keyAddress, uintptr_t tagAddress, uint32_t tag,
                                int64_t timeoutNs);
Result SignalProcessWideKey(uintptr_t address, int32_t value);
int64_t GetSystemTick();
Result ConnectToNamedPort(Handle* outHandle, const char* portName);
Result SendSyncRequestLight(Handle handle);
Result SendSyncRequest(Handle handle);
Result SendSyncRequestWithUserBuffer(uintptr_t address, size_t size, Handle handle);
Result SendAsyncRequestWithUserBuffer(Handle* outHandle, uintptr_t address, size_t size,
                                      Handle handle);
Result GetProcessId(uint64_t* outProcessId, Handle handle);
Result GetThreadId(uint64_t* outThreadId, Handle handle);
Result Break(BreakReason reason, uintptr_t, size_t);
Result OutputDebugString(const char* message, size_t size);
void ReturnFromException(Result result);
Result GetInfo(uint64_t* outInfo, InfoType infotype, Handle handle, uint64_t infoSubType);
void FlushEntireDataCache();
Result FlushDataCache(uintptr_t address, size_t size);
Result MapPhysicalMemory(uintptr_t address, size_t size);
Result UnmapPhysicalMemory(uintptr_t address, size_t size);
Result GetLastThreadInfo(svc::lp::LastThreadContext* outContext, uintptr_t* outTlsAddress,
                         uint32_t* outFlags);
Result GetResourceLimitLimitValue(int64_t* outLimit, Handle handle, LimitableResource resource);
Result GetResourceLimitCurrentValue(int64_t* outCurrentValue, Handle handle,
                                    LimitableResource resource);
Result SetThreadActivity(Handle handle, ThreadActivity activity);
Result GetThreadContext3(ThreadContext* outThreadContext, Handle handle);
Result DumpInfo(DumpInfoType dumpInfoType, uint64_t);
Result ReadWriteRegister(uint32_t* outValue, uint64_t registerAddress, uint32_t rwMask,
                         uint32_t value);
Result SetProcessActivity(Handle handle, ProcessActivity activity);
Result CreateSharedMemory(Handle* outHandle, size_t size, MemoryPermission localMemoryPermission,
                          MemoryPermission remoteMemoryPermission);
Result MapTransferMemory(Handle handle, uintptr_t address, size_t size,
                         MemoryPermission memoryPermission);
Result UnmapTransferMemory(Handle handle, uintptr_t address, size_t size);
Result CreateInterruptEvent(Handle* outHandle, InterruptEvent interruptEvent,
                            InterruptEventType eventType);
Result QueryPhysicalAddress(svc::lp::PhysicalMemoryInfo* outPhysicalMemoryInfo,
                            uintptr_t virtualAddress);
Result QueryIoMapping(uintptr_t* outVirtualAddress, uint64_t ioAddress, size_t size);
Result CreateDeviceAddressSpace(Handle* outHandle, uint64_t startAddress, uint64_t endAddress);
Result AttachDeviceAddressSpace(DeviceName deviceName, Handle handle);
Result DetachDeviceAddressSpace(DeviceName deviceName, Handle handle);
Result MapDeviceAddressSpaceByForce(Handle deviceAddressSpaceHandle, Handle processHandle,
                                    uint64_t processAddress, size_t size, uint64_t deviceAddress,
                                    MemoryPermission memoryPermission);
Result MapDeviceAddressSpaceAligned(Handle deviceAddressSpaceHandle, Handle processHandle,
                                    uint64_t processAddress, size_t size, uint64_t deviceAddress,
                                    MemoryPermission memoryPermission);
Result MapDeviceAddressSpace(size_t* outMappedSize, Handle deviceAddressSpaceHandle,
                             Handle processHandle, uint64_t processAddress, size_t size,
                             uint64_t deviceAddress, MemoryPermission memoryPermission);
Result UnmapDeviceAddressSpace(Handle deviceAddressSpaceHandle, Handle processHandle,
                               uint64_t processAddress, size_t size, uint64_t deviceAddress,
                               MemoryPermission memoryPermission);
Result InvalidateProcessDataCache(Handle handle, uint64_t address, uint64_t size);
Result StoreProcessDataCache(Handle handle, uint64_t address, uint64_t size);
Result FlushProcessDataCache(Handle handle, uint64_t address, uint64_t size);
Result DebugActiveProcess(Handle handle, uint64_t processId);
Result BreakDebugProcess(Handle handle);
Result TerminateDebugProcess(Handle handle);
Result GetDebugEvent(svc::lp::DebugEventInfo* outDebugEventInfo, Handle handle);
#if NN_SDK_VER >= NN_MAKE_VER(3, 0, 0)
Result ContinueDebugEvent(Handle handle, uint32_t flags, const uint64_t* threadIds,
                          uint32_t threadIdCount);
#else
Result ContinueDebugEvent(Handle handle, uint32_t flags, uint64_t threadId);
#endif
Result GetProcessList(int32_t* outProcessIdCount, uint64_t* outProcessIds,
                      int32_t maxProcessIdCount);
Result GetThreadList(int32_t* outThreadIdCount, uint64_t* outThreadIds, int32_t maxThreadIdCount,
                     Handle handle);
Result GetDebugThreadContext(ThreadContext* outThreadContext, Handle handle, uint64_t threadId,
                             uint32_t flags);
Result SetDebugThreadContext(Handle handle, uint64_t threadId, const ThreadContext& threadContext,
                             uint32_t flags);
Result QueryDebugProcessMemory(svc::lp::MemoryInfo* outMemoryInfo, PageInfo* outPageInfo,
                               Handle handle, uintptr_t address);
Result ReadDebugProcessMemory(uintptr_t bufferAddress, Handle handle, uintptr_t srcAddress,
                              size_t size);
Result WriteDebugProcessMemory(Handle handle, uintptr_t bufferAddress, uintptr_t dstAddress,
                               size_t size);
Result SetHardwareBreakPoint(HardwareBreakPointRegisterName registerName, uint64_t flags,
                             uint64_t value);
Result GetDebugThreadParam(uint64_t*, uint32_t*, Handle handle, uint64_t threadId,
                           DebugThreadParam param);
Result CreateSession(Handle* outServerHandle, Handle* outClientHandle, bool isLight, uintptr_t);
Result AcceptSession(Handle* outPortHandle, Handle sessionHandle);
Result ReplyAndReceiveLight(Handle handle);
Result ReplyAndReceive(int32_t* outHandleIndex, const Handle* handles, int32_t handleCount,
                       Handle handle, int64_t timeout);
Result ReplyAndReceiveWithUserBuffer(int32_t* outHandleIndex, uintptr_t bufferAddress,
                                     size_t bufferSize, const Handle* handles, int32_t handleCount,
                                     Handle handle, int64_t timeout);
Result CreateEvent(Handle* outWritableEventHandle, Handle* outReadableEventHandle);
void SleepSystem();
Result CreatePort(Handle* outServerHandle, Handle* outClientHandle, int32_t maxSessionCount,
                  bool isLight, uintptr_t);
Result ManageNamedPort(Handle* outServerHandle, const char* name, int32_t maxSessionCount);
Result ConnectToPort(Handle* outSessionHandle, Handle handle);
Result SetProcessMemoryPermission(Handle handle, uint64_t address, uint64_t size,
                                  MemoryPermission memoryPermission);
Result MapProcessMemory(uintptr_t dstAddress, Handle handle, uint64_t srcAddress, size_t size);
Result UnmapProcessMemory(uintptr_t dstAddress, Handle handle, uint64_t srcAddress, size_t size);
Result QueryProcessMemory(svc::lp::MemoryInfo* outMemoryInfo, PageInfo* outPageInfo, Handle handle,
                          uint64_t address);
Result MapProcessCodeMemory(Handle handle, uint64_t dstAddress, uint64_t srcAddress, uint64_t size);
Result UnmapProcessCodeMemory(Handle handle, uint64_t dstAddress, uint64_t srcAddress,
                              uint64_t size);
Result CreateProcess(Handle* outHandle, const svc::lp::CreateProcessParameter& parameter,
                     const uint32_t* capabilities, int32_t capabilityCount);
Result StartProcess(Handle handle, int32_t priority, int32_t defaultCpuId, uint64_t stackSize);
Result TerminateProcess(Handle handle);
Result GetProcessInfo(int64_t* outProcessInfo, Handle handle, ProcessInfoType processInfoType);
Result CreateResourceLimit(Handle* outHandle);
Result SetResourceLimitLimitValue(Handle handle, LimitableResource resource, int64_t value);
void CallSecureMonitor();

#ifdef __aarch64__
}  // namespace lp
#endif

}  // namespace aarch

}  // namespace nn::svc
