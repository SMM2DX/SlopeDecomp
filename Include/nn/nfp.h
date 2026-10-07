#pragma once

#include <cstdint>

#include "nfp/nfp_Types.h"
#include "nn_Result.h"
#include "os.h"

namespace nn::nfp {

Result Initialize();
Result Finalize();

Result ListDevices(DeviceHandle* out, int32_t* totalOut, int32_t count);
Result StartDetection(const DeviceHandle& handle);
Result StopDetection(const DeviceHandle& handle);
Result Mount(const DeviceHandle& handle, ModelType modelType, MountTarget mountTarget);
Result Unmount(const DeviceHandle& handle);

Result OpenApplicationArea(const DeviceHandle& handle, uint32_t appId);
Result GetApplicationArea(void* buf, uint32_t* outSize, const DeviceHandle& handle,
                          uint64_t bufSize);
Result SetApplicationArea(const DeviceHandle& handle, const void* buf, uint64_t bufSize);
Result Flush(const DeviceHandle& handle);
Result Restore(const DeviceHandle& handle);

Result GetTagInfo(TagInfo* out, const DeviceHandle& handle);
Result GetRegisterInfo(RegisterInfo* out, const DeviceHandle& handle);
Result GetCommonInfo(CommonInfo* out, const DeviceHandle& handle);
Result GetModelInfo(ModelInfo* out, const DeviceHandle& handle);

Result AttachActivateEvent(nn::os::SystemEventType* outEvent, const DeviceHandle& handle);
Result AttachDeactivateEvent(nn::os::SystemEventType* outEvent, const DeviceHandle& handle);
Result AttachAvailabilityChangeEvent(nn::os::SystemEventType* outEvent);

State GetState();
DeviceState GetDeviceState(const DeviceHandle& handle);
Result GetNpadId(uint32_t* out, const DeviceHandle& handle);

}  // namespace nn::nfp
