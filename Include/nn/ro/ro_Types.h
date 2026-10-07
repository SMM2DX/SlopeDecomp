#pragma once

#include "ro/detail/ro_RoModule.h"
#include "util/util_BinTypes.h"

namespace nn::ro {

class Module {
public:
    detail::RoModule* ModuleObject;
    uint32_t State;
    void* NroPtr;
    void* BssPtr;
    void* _x20;
    void* SourceBuffer;
    char Name[256]; /* Created by retype action */
    uint8_t _x130;
    uint8_t _x131;
    bool isLoaded;  // bool
};

struct ModuleId {
    uint8_t build_id[0x20];
};

struct NroHeader {
    static constexpr uint32_t NroMagic = util::MakeSignature('N', 'R', 'O', '0');

    uint32_t entrypoint_insn;
    uint32_t mod_offset;
    uint8_t _x8[0x8];
    uint32_t magic;
    uint8_t _x14[0x4];
    uint32_t size;
    uint8_t _x1c[0x4];
    uint32_t text_offset;
    uint32_t text_size;
    uint32_t ro_offset;
    uint32_t ro_size;
    uint32_t rw_offset;
    uint32_t rw_size;
    uint32_t bss_size;
    uint8_t _x3c[0x4];
    ModuleId module_id;
    uint8_t _x60[0x20];
};
static_assert(sizeof(NroHeader) == 0x80, "NroHeader definition!");

struct ProgramId {
    uint64_t value;

    explicit operator uint64_t() const { return this->value; }
};

struct NrrCertification {
    uint64_t programID_Mask;
    uint64_t programID_Pattern;
    uint8_t reserved_x10[0x10];

    uint8_t modulus[0x100];
    uint8_t signature[0x100];
};
static_assert(sizeof(NrrCertification) == 0x220, "NrrCertification definition!");

enum NrrKind : uint8_t {
    NrrKind_User = 0,
    NrrKind_JitPlugin = 1,
    NrrKind_Count = 2,
};

struct NrrHeader {
    static constexpr uint32_t NrrMagic = util::MakeSignature('N', 'R', 'R', '0');

    uint32_t magic;
    uint8_t _x4[0xC];
    NrrCertification certiicate;
    uint8_t nrr_signature[0x100];
    ProgramId program_id;
    uint32_t size;
    NrrKind type; /* 7.0.0+ */
    uint8_t _x33d[3];
    uint32_t hashes_offset;
    uint32_t num_hashes;
    uint8_t _x348[8];
};
static_assert(sizeof(NrrHeader) == 0x350, "NrrHeader definition!");

struct RegistrationInfo {
    enum State {
        State_Unregistered,
        State_Registered,
    };
    State state;
    NrrHeader* nrrPtr;
    uint64_t _x10;
    uint64_t _x18;
};

enum BindFlag {
    BindFlag_Now = 1,
    BindFlag_Lazy = 2,
};

}  // namespace nn::ro
