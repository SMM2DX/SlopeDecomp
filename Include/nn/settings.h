#pragma once

#include <cstdint>

#include "nn_Result.h"

namespace nn::settings {
enum Language {
    Language_Japanese,
    Language_English,
    Language_French,
    Language_German,
    Language_Italian,
    Language_Spanish,
    Language_Chinese,
    Language_Korean,
    Language_Dutch,
    Language_Portuguese,
    Language_Russian,
    Language_Taiwanese,
    Language_BritishEnglish,
    Language_CanadianFrench,
    Language_LatinAmericanSpanish,
};

struct LanguageCode {
    char code[0x8];

    static LanguageCode Make(nn::settings::Language);
};

bool operator==(nn::settings::LanguageCode const&, nn::settings::LanguageCode const&);
bool operator==(nn::settings::Language const&, nn::settings::LanguageCode const&);

namespace system {
struct FirmwareVersion {
    uint8_t major;
    uint8_t minor;
    uint8_t micro;
    uint8_t padding1;
    uint8_t revision_major;
    uint8_t revision_minor;
    uint8_t padding2;
    uint8_t padding3;
    char platform[0x20];
    char version_hash[0x40];
    char display_version[0x18];
    char display_title[0x80];

    constexpr uint32_t getVersion() const {
        return (static_cast<uint32_t>(major) << 16) | (static_cast<uint32_t>(minor) << 8) |
               (static_cast<uint32_t>(micro) << 0);
    }
};

Result GetFirmwareVersion(FirmwareVersion*);
}  // namespace system

}  // namespace nn::settings
