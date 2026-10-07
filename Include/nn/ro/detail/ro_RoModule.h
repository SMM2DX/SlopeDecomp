#pragma once

#include <elf.h>

namespace nn::ro::detail {

class RoModule {
public:
    RoModule* next;
    RoModule* prev;
    union {
        Elf64_Rel* rel_plt;
        Elf64_Rela* rela_plt;
        void* rel_rela_plt;
    };
    union {
        Elf64_Rel* rel;
        Elf64_Rela* rela;
        void* rel_rela;
    };
    uint8_t* moduleBaseAddr;
    Elf64_Dyn* dynamic;
    bool is_rela;
    uint8_t pad_x31[7];
    Elf64_Xword plt_size;
    void (*initFunc)();
    void (*finiFunc)();
    Elf64_Word* hashBucket;
    Elf64_Word* hashChain;
    char* dynstrTable;
    Elf64_Sym* dynsymTable;
    Elf64_Xword dynstrTable_size;
    void** got_plt;
    Elf64_Xword rela_dyn_size;
    Elf64_Xword rel_dyn_size;
    Elf64_Xword relEnt_count;
    Elf64_Xword relaEnt_count;
    Elf64_Xword nchain;
    Elf64_Xword nbucket;
    Elf64_Xword off_soname;
    uint64_t unk_xb8;
    bool unk_xc0;
    uint8_t pad_xc1[7];
    Elf64_Xword ArchitectureData;

    void Initialize(uint8_t* moduleBaseAddr, uint64_t arg1_0, Elf64_Dyn* dynamic, bool arg4_0);
    Elf64_Sym* Lookup(const char* symbol);
    void Relocation(bool lazyGotPlt);
    void CallInit();
    void CallFini();
    bool ResolveSym(Elf64_Addr* symbolAddr, Elf64_Sym* symbol);
};

static_assert(sizeof(RoModule) == 0xD0, "RoModule definition!");
}  // namespace nn::ro::detail
