#pragma once

#include "settings.h"

namespace nn::err {
enum ErrorCodeCategoryType : uint32_t {
    unk1,
    unk2,
};

class ApplicationErrorArg {
public:
    ApplicationErrorArg();
    ApplicationErrorArg(uint32_t error_code, const char* dialog_message,
                        const char* fullscreen_message,
                        const nn::settings::LanguageCode& languageCode);
    void SetApplicationErrorCodeNumber(uint32_t error_code);
    void SetDialogMessage(const char* message);
    void SetFullScreenMessage(const char* message);

    uint64_t unk;
    uint32_t error_code;
    nn::settings::LanguageCode language_code;
    char dialog_message[2048];
    char fullscreen_message[2048];
};

uint32_t MakeErrorCode(ErrorCodeCategoryType err_category_type, uint32_t errorCodeNumber);
void ShowApplicationError(const ApplicationErrorArg& arg);
}  // namespace nn::err
