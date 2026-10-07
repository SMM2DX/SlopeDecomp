/**
 * @brief Visual interface implementation.
 */

#pragma once

#include "os.h"

namespace nn::vi {

enum LayerStack {
    Default = 0,
    Lcd = 1,
    Screenshot = 2,
    Recording = 3,
    LastFrame = 4,
    Arbitrary = 5,
    ApplicationForDebug = 6,
    Null = 10,
};

struct DisplayName {
    static constexpr uint32_t maxNameLen = 64;
    char data[maxNameLen];
};

struct DisplayInfo {
    DisplayName name;
    bool hasLayerLimit;
    int64_t maxLayers;
    int64_t maxWidth;
    int64_t maxHeight;
};

// Needs to be >128 bits, nnsdk uses X8 (indirect result register)
struct IDisplayService {
    uintptr_t servicePtr;
    uintptr_t _x8[5];
};

typedef IDisplayService IManagerDisplayService;
typedef IDisplayService ISystemDisplayService;

class Display;
class Layer;
class NativeWindow;

struct LayerCreationSettings {
    LayerCreationSettings();
    LayerCreationSettings(int32_t width, int32_t height);
    int32_t GetWidth() const;
    void SetWidth(int32_t width);
    int32_t GetHeight() const;
    void SetHeight(int32_t height);
    void SetFullscreen(bool isFullscreen);
    bool IsFullscreen() const;
    void SetVisibility(bool isVisible);
    bool IsVisible() const;

private:
    int32_t width;
    int32_t height;

    union {
        uint32_t rawFlags;
        struct {
            bool fullScreen : 1;  // defaults to false
            bool visible : 1;     // defaults to true
        };
    };
};

enum ScalingMode { None, Exact, FitLayer, ScaleAndCrop, PreserveAspectRatio };

void Initialize();
void InitializeMinimum();
void Finalize();
void FinalizeMinimum();

IDisplayService GetService();
ISystemDisplayService GetSystemService();
IManagerDisplayService GetManagerService();

Result SetContentVisibility(bool visibility);
Result ListDisplays(nn::vi::DisplayInfo* outInfo, int count);
Result OpenDefaultDisplay(nn::vi::Display** outDisplay);
Result OpenDisplay(nn::vi::Display** outDisplay, const char* displayName);
Result CloseDisplay(nn::vi::Display* inDisplay);
Result GetDisplayVsyncEvent(nn::os::SystemEventType* outEvent, nn::vi::Display* inDisplay);
int32_t GetZOrderCountMin(const nn::vi::Display* inDisplay);
int32_t GetZOrderCountMax(const nn::vi::Display* inDisplay);
Result GetDisplayLogicalResolution(int32_t* width, int32_t* height,
                                   const nn::vi::Display* inDisplay);
Result GetDisplayResolution(int32_t* width, int32_t* height, const nn::vi::Display* inDisplay);
uint64_t GetDisplayIdWithValidation(const nn::vi::Display* inDisplay);
Result GetLatestFrameNumber(uint64_t* pOutFrameNumber, const Layer* pLayer);

Result CreateLayer(nn::vi::Layer** outLayer, nn::vi::Display* inDisplay);
Result CreateLayer(nn::vi::Layer** outLayer, nn::vi::Display* inDisplay,
                   const nn::vi::LayerCreationSettings* inSettings);
Result CreateLayer(nn::vi::Layer** outLayer, nn::vi::Display* inDisplay, int32_t width,
                   int32_t height);
void DestroyLayer(nn::vi::Layer* inLayer);
Result GetNativeWindow(void** outWindow, nn::vi::Layer* inLayer);

Result SetLayerScalingMode(nn::vi::Layer* layer, nn::vi::ScalingMode scalingMode);
Result SetLayerPosition(nn::vi::Layer* inLayer, float x, float y);
Result SetLayerSize(nn::vi::Layer* inLayer, int32_t width, int32_t height);
Result SetLayerZ(nn::vi::Layer* inLayer, int32_t z);
Result GetLayerZ(int32_t* z, const nn::vi::Layer* inLayer);
Result SetLayerVisibility(nn::vi::Layer* inLayer, bool isVisible);
Result SetLayerAlpha(nn::vi::Layer* inLayer, float alpha);

Result AddToLayerStack(nn::vi::Layer* inLayer, nn::vi::LayerStack layerStackType);
Result RemoveFromLayerStack(nn::vi::Layer* inLayer, nn::vi::LayerStack layerStackType);
uint64_t GetLayerIdWithValidation(const nn::vi::Layer* inLayer);
}  // namespace nn::vi
