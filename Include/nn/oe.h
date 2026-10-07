/**
 * @brief Extenstions to OS functions.
 */

#pragma once

#include <cstddef>

#include "album/album_Types.h"
#include "settings.h"

namespace nn::oe {

enum OperationMode {
    OperationMode_Handheld,
    OperationMode_Docked,
};

enum PerformanceMode {
    PerformanceMode_Normal = 0,
    PerformanceMode_Boost = 1,
    PerformanceMode_Invalid = -1,
};

enum FocusHandlingMode {
    FocusHandlingMode_SuspendHomeSleep,
    FocusHandlingMode_NoSuspend,
    FocusHandlingMode_SuspendHomeSleepNotify,
    FocusHandlingMode_AlwaysSuspend,
};

enum FocusState {
    FocusState_InFocus = 1,
    FocusState_OutOfFocus = 2,
    FocusState_Background = 3,
};

struct DisplayVersion {
    char name[16];
};

typedef int32_t PerformanceConfiguration;

void Initialize();
void FinishStartupLogo();
void EnableGamePlayRecording(void*, uint64_t);
void SetExpectedVolumeBalance(float, float);
void SetPerformanceConfiguration(nn::oe::PerformanceMode, nn::oe::PerformanceConfiguration);
void SetResumeNotificationEnabled(bool);
void SetOperationModeChangedNotificationEnabled(bool);
void SetPerformanceModeChangedNotificationEnabled(bool);
void SetFocusHandlingMode(nn::oe::FocusHandlingMode);
void SetScreenShotImageOrientation(nn::album::ImageOrientation);
void SetUserInactivityDetectionTimeExtended(bool);
bool IsUserInactivityDetectionTimeExtended();
bool TryPopNotificationMessage(uint32_t*);
bool TryPopLaunchParameter(size_t*, void*, size_t);
void GetExpectedVolumeBalance(float*, float*);
void GetDisplayVersion(DisplayVersion*);
FocusState GetCurrentFocusState();
OperationMode GetOperationMode();
PerformanceMode GetPerformanceMode();
nn::settings::LanguageCode GetDesiredLanguage();

}  // namespace nn::oe
