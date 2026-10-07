#pragma once

#include <cstdint>
#include <cstdlib>

#include "applet.h"
#include "nn_Result.h"
#include "util.h"

namespace nn::swkbd {

enum class Preset {
    Default,
    Password,
    UserName,
    DownloadCode,
    Max_Preset,
};

enum class KeyboardMode {
    ModeLanguageSet1,
    ModeNumeric,
    ModeASCII,
    ModeLanguageSet1Latin,
    ModeAlphabet,
    ModeSimplifiedChinese,
    ModeTraditionalChinese,
    ModeKorean,
    ModeLanguageSet2,
    ModeMax_KeyboardMode,
    ModeFull,
    ModeFullLatin,
};

enum class InvalidChar {
    Space = 1 << 1,
    AtMark = 1 << 2,
    Percent = 1 << 3,
    Slash = 1 << 4,
    BackSlash = 1 << 5,
    Numeric = 1 << 6,
    OutsideOfDownloadCode = 1 << 7,
    OutsideOfMiiNickName = 1 << 8,
    Force32 = 1 << 9,
};

enum class PasswordMode {
    Show,
    Hide,
    Max_PasswordMode,
};

enum class InputFormMode {
    OneLine,
    MultiLine,
    Separate,
    Max_InputFormMode,
};

enum class InitialCursorPos {
    First,
    Last,
    Max_InitialCursorPos,
};

enum class TextCheckResult {
    Success,
    ShowFailureDialog,
    ShowConfirmDialog,
    Max_TextCheckResult,
};

enum class DictionaryLang {
    Japanese,
    AmericanEnglish,
    CanadianFrench,
    LatinAmericanSpanish,
    Reserved1,
    BritishEnglish,
    French,
    German,
    Spanish,
    Italian,
    Dutch,
    Portuguese,
    Russian,
    Reserved2,
    SimplifiedChinesePinyin,
    TraditionalChineseCangjie,
    TraditionalChineseSimplifiedCangjie,
    TraditionalChineseZhuyin,
    Korean,
    Max_DictionaryLang,
};

enum class CloseResult { Enter, Cancel };

enum class Trigger : uint8_t { Default };

struct DictionaryInfo {
    uint32_t offset;
    uint16_t size;
    DictionaryLang lang;
};

struct KeyboardConfig {
    KeyboardMode keyboardMode;
    char okText[0x12];
    char16_t leftOptionalSymbolKey;
    char16_t rightOptionalSymbolKey;
    bool isPredictionEnabled;
    InvalidChar invalidCharFlag;
    InitialCursorPos initialCursorPos;
    char headerText[0x82];
    char subText[0x102];
    char guideText[0x202];
    int32_t textMaxLength;
    int32_t textMinLength;
    PasswordMode passwordMode;
    InputFormMode inputFormMode;
    bool isUseNewLine;
    bool isUseUtf8;
    bool isUseBlurBackground;
    int32_t initialStringOffset;
    int32_t initialStringLength;
    int32_t userDictionaryOffset;
    int32_t userDictionaryNum;
    bool isUseTextCheck;

#if NN_SDK_VER < NN_MAKE_VER(6, 0, 0)
    void* textCheckCallback;
#endif

#if NN_SDK_VER >= NN_MAKE_VER(3, 0, 0)
    int32_t separateTextPos[0x8];
#endif

#if NN_SDK_VER >= NN_MAKE_VER(6, 0, 0)
    uint64_t customDictionaryEntries[0x18];
    uint8_t customDictionaryNum;
#endif

#if NN_SDK_VER >= NN_MAKE_VER(8, 0, 0)
    uint8_t isCancelButtonDisabled;
    uint8_t filler[0xd];
    Trigger trigger;
    uint8_t filler2[0x4];
#endif
};

struct ShowKeyboardArg {
    KeyboardConfig keyboardConfig;
    const char* workBuf;
    long workBufSize;
    const char* textCheckWorkBuf;
    long textCheckWorkBufSize;
    const char* _customizeDicBuf;
    long _customizeDicBufSize;
};

class String {
public:
    String(int32_t size) {
        bufsize = size;
        strBuf = nullptr;
    }
    String(int32_t size, char* buf) {
        bufsize = size;
        strBuf = buf;
    }

    void allocate() { strBuf = (char*)malloc(bufsize); }

    void setBuf(char* buf) { strBuf = buf; }

    const char* cstr() { return strBuf; }

private:
    char* strBuf;
    size_t bufsize;
};

struct UserWord;   // TODO contents missing
struct KbdConfig;  // TODO contents missing

struct CustomizedDictionarySet {
    void* buffer;        // 0x1000-byte aligned buffer.
    int32_t bufferSize;  // 0x1000-byte aligned buffer size.
    uint64_t entries[0x18];
    uint16_t totalEntries;
};

#if NN_SDK_VER >= NN_MAKE_VER(8, 0, 0)
using TextCheckCb = TextCheckResult (*)(void*, uint32_t*, String*);
#else
using TextCheckCb = TextCheckResult (*)(void*, uint64_t*, String*);
#endif

int32_t ConvertUtf8ToUtf16(void*, int32_t, const char*, int32_t);
int32_t ConvertUtf8ToUtf16(void*, int32_t, const char*);
int32_t GetLengthOfConvertedStringUtf8ToUtf16(const char*);
void MakePresetDefault(KeyboardConfig*);
void MakePresetPassword(KeyboardConfig*);
void MakePresetUsername(KeyboardConfig*);
void MakePresetDownloadCode(KeyboardConfig*);
Result GetInteractiveOutStorageCallback(nn::applet::LibraryAppletHandle, String*,
                                        const ShowKeyboardArg&);
size_t GetRequiredTextCheckWorkBufferSize();
void ReadCloseResultAndString(nn::applet::LibraryAppletHandle, CloseResult*, String*);
void CopyInitialStringInfo(ShowKeyboardArg*, int32_t);
void CopyUserDictionaryInfo(ShowKeyboardArg*, int32_t);

#if NN_SDK_VER >= NN_MAKE_VER(6, 0, 0)
void keyboardConfig2kbdConfig(const KeyboardConfig&, KbdConfig*);
#endif

Result ShowKeyboard(String*, const ShowKeyboardArg&);

#if NN_SDK_VER >= NN_MAKE_VER(8, 0, 0)
Result ShowKeyboard(String*, const ShowKeyboardArg&, Trigger);
#endif

void InitializeKeyboardConfig(KeyboardConfig*);
void MakePreset(KeyboardConfig*, Preset);

size_t GetRequiredWorkBufferSize(bool);
#if NN_SDK_VER >= NN_MAKE_VER(1, 0, 0)
size_t GetRequiredWorkBufferSize(int32_t);
#endif

size_t GetRequiredStringBufferSize();
void SetOkText(KeyboardConfig*, const char16_t*);
void SetOkTextUtf8(KeyboardConfig*, const char*);
void SetLeftOptionalSymbolKey(KeyboardConfig*, char16_t);
void SetLeftOptionalSymbolKeyUtf8(KeyboardConfig*, const char*);
void SetRightOptionalSymbolKey(KeyboardConfig*, char16_t);
void SetRightOptionalSymbolKeyUtf8(KeyboardConfig*, const char*);
void SetHeaderText(KeyboardConfig*, const char16_t*);
void SetHeaderTextUtf8(KeyboardConfig*, const char*);
void SetSubText(KeyboardConfig*, const char16_t*);
void SetSubTextUtf8(KeyboardConfig*, const char*);
void SetGuideText(KeyboardConfig*, const char16_t*);
void SetGuideTextUtf8(KeyboardConfig*, const char*);
void SetInitialText(ShowKeyboardArg*, const char16_t*);
void SetInitialTextUtf8(ShowKeyboardArg*, const char*);
void SetUserWordList(ShowKeyboardArg*, const UserWord*, int32_t);

#if NN_SDK_VER >= NN_MAKE_VER(6, 0, 0)
void SetCustomizedDictionaries(ShowKeyboardArg*, const CustomizedDictionarySet&);
#endif

void SetTextCheckCallback(ShowKeyboardArg*, TextCheckCb);

extern nn::applet::ExitReason g_ExitReason;
#if NN_SDK_VER < NN_MAKE_VER(4, 0, 0)
nn::applet::ExitReason getExitReason();
#endif

}  // namespace nn::swkbd
