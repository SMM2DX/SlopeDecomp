#pragma once

#include "irsensor/irsensor_ClusteringData.h"
#include "irsensor/irsensor_ClusteringProcessorConfig.h"
#include "irsensor/irsensor_ClusteringProcessorState.h"
#include "irsensor/irsensor_DpdProcessorConfig.h"
#include "irsensor/irsensor_DpdProcessorPointingState.h"
#include "irsensor/irsensor_DpdProcessorState.h"
#include "irsensor/irsensor_HandAnalysisConfig.h"
#include "irsensor/irsensor_ImageTransferProcessorConfig.h"
#include "irsensor/irsensor_ImageTransferProcessorFormat.h"
#include "irsensor/irsensor_ImageTransferProcessorState.h"
#include "irsensor/irsensor_MomentProcessorConfig.h"
#include "irsensor/irsensor_MomentProcessorState.h"
#include "irsensor/irsensor_MomentStatistic.h"
#include "irsensor/irsensor_Rect.h"
#include "nn_Result.h"
#include "util.h"

namespace nn::irsensor {

struct TeraPluginProcessorConfig;
struct TeraPluginProcessorState;

enum class IrCameraStatus : uint32_t {
    Available,
    Unsupported,
    Unconnected,
};

struct IrCameraHandle {
    uint8_t playerNumber;
    uint8_t deviceType;
    uint8_t reserved[2];
};

IrCameraHandle GetIrCameraHandle(const uint32_t&);
void Initialize(const IrCameraHandle& handle);
void Finalize(const IrCameraHandle& handle);
IrCameraStatus GetIrCameraStatus(const IrCameraHandle& handle);
void StopImageProcessor(const IrCameraHandle& handle);

void GetMomentProcessorDefaultConfig(MomentProcessorConfig* outConfig);
void RunMomentProcessor(const IrCameraHandle& handle, const MomentProcessorConfig& config);
Result GetMomentProcessorState(MomentProcessorState* outState, const IrCameraHandle& handle);
Result GetMomentProcessorStates(MomentProcessorState* outStates, int32_t* outCount, int32_t,
                                const IrCameraHandle& handle);
MomentStatistic CalculateMomentRegionStatistic(const MomentProcessorState* state, const Rect&,
                                               int32_t, int32_t, int32_t, int32_t);

void GetClusteringProcessorDefaultConfig(ClusteringProcessorConfig* outConfig);
void RunClusteringProcessor(const IrCameraHandle& handle, const ClusteringProcessorConfig& config);
Result GetClusteringProcessorState(ClusteringProcessorState* outState,
                                   const IrCameraHandle& handle);
Result GetClusteringProcessorStates(ClusteringProcessorState* outStates, int32_t* outCount, int32_t,
                                    const IrCameraHandle& handle);

void GetImageTransferProcessorDefaultConfig(ImageTransferProcessorConfig* outConfig);
void RunImageTransferProcessor(const IrCameraHandle& handle,
                               const ImageTransferProcessorConfig& config, void*, uint64_t);
Result GetImageTransferProcessorState(ImageTransferProcessorState* outState, void*, uint64_t,
                                      const IrCameraHandle& handle);

Result RunHandAnalysis(const IrCameraHandle& handle, const HandAnalysisConfig& config);

Result RunTeraPluginProcessor(const IrCameraHandle& handle,
                              const TeraPluginProcessorConfig& config);

#if NN_SDK_VER <= NN_MAKE_VER(4, 0, 0)
void RunDpdProcessor(const IrCameraHandle& handle);
void GetDpdProcessorDefaultConfig(DpdProcessorConfig* outConfig);
void RunDpdProcessor(const IrCameraHandle& handle, const DpdProcessorConfig& config);
Result GetDpdProcessorStates(DpdProcessorPointingState* outStates, int32_t* outCount, int32_t,
                             const IrCameraHandle& handle);
Result GetDpdProcessorStates(DpdProcessorState* outStates, int32_t* outCount, int32_t,
                             const IrCameraHandle& handle);
#endif

Result GetTeraPluginProcessorStates(TeraPluginProcessorState* outStates, int32_t* outCount, int32_t,
                                    long, uint32_t, int32_t, const IrCameraHandle& handle);

}  // namespace nn::irsensor
