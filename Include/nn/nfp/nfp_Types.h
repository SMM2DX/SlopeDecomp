#pragma once

#include <cstdint>
namespace nn::nfp {

struct DeviceHandle {
    uint64_t m_Id;
};

const int32_t AmiiboNameLength = 10;

enum State : uint32_t {
    State_NonInitialized = 0,
    State_Initialized = 1,
};

enum DeviceState : uint32_t {
    DeviceState_Initialized = 0,
    DeviceState_SearchingForTag = 1,
    DeviceState_TagFound = 2,
    DeviceState_TagRemoved = 3,
    DeviceState_TagMounted = 4,
    DeviceState_Unavailable = 5,
    DeviceState_Finalized = 6,
};

enum ModelType : uint32_t {
    ModelType_Amiibo = 0,
};

enum MountTarget : uint32_t {
    MountTarget_None = 0,
    MountTarget_Rom = 1,
    MountTarget_Ram = 2,
    MountTarget_All = 3,
};

enum TagType : uint32_t {
    TagType_None = 0,
    TagType_Type1 = 1U << 0,
    TagType_Type2 = 1U << 1,
    TagType_Type3 = 1U << 2,
    TagType_Type4A = 1U << 3,
    TagType_Type4B = 1U << 4,
    TagType_Type5 = 1U << 5,
    TagType_Mifare = 1U << 6,
    TagType_All = 0xFFFFFFFF,
};

enum Protocol : uint32_t {
    Protocol_None = 0,
    Protocol_TypeA = 1,
    Protocol_TypeB = 1 << 1,
    Protocol_TypeF = 1 << 2,
    Protocol_All = 0xFFFFFFFF,
};

struct AmiiboDate {
    int16_t year;
    int8_t month;
    int8_t day;
};

struct TagId {
    uint8_t uuid[10];
    uint8_t uuidLength;
    char reserved[0x15];
};

struct TagInfo {
    TagId id;
    Protocol protocol;
    TagType type;
    char reserved2[0x30];
};

struct CommonInfo {
    AmiiboDate lastWriteDate;
    uint16_t writeCounter;
    uint16_t version;
    uint32_t applicationAreaSize;
    char reserved[0x34];
};

struct ModelInfo {
    uint8_t gameId;
    uint8_t characterId;
    uint8_t characterVariant;
    uint8_t amiiboType;
    uint16_t modelNumber;
    uint8_t series;
    char reserved[0x39];
};

struct RegisterInfo {
    char miiStoreData[0x44];  // nn::mii::StoreData
    AmiiboDate registerDate;
    char nickname[(AmiiboNameLength * 4) + 1];  // utf-8, null-terminated
    uint8_t fontRegion;
    char reserved[0x7a];
};

}  // namespace nn::nfp
