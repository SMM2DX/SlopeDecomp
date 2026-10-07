/**
 * @brief Crypto service implementation.
 */

#pragma once

#include "nn_Result.h"

namespace nn::crypto {

class Sha256Context;

// dstBufferSize max size is 0x38
Result GenerateCryptographicallyRandomBytes(void* dstBuffer, uint64_t dstBufferSize);
bool IsSameBytes(const void* data1, const void* data2, uint64_t size);

// MD5 Hash
void GenerateMd5Hash(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                     uint64_t srcBufferSize);

// SHA-1 Hash
void GenerateSha1Hash(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                      uint64_t srcBufferSize);

// SHA-256 Hash
void GenerateSha256Hash(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                        uint64_t srcBufferSize);

// SHA-512 Hash
void GenerateSha512Hash(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                        uint64_t srcBufferSize);

// HMAC-SHA1
void GenerateHmacSha1Mac(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                         uint64_t srcBufferSize, const void* hmacKey, uint64_t hmacKeySize);

// HMAC-SHA256
void GenerateHmacSha256Mac(void* dstBuffer, uint64_t dstBufferSize, const void* srcBuffer,
                           uint64_t srcBufferSize, const void* hmacKey, uint64_t hmacKeySize);

// AES-128 CBC Decrypt - returns srcBufferSize
uint64_t DecryptAes128Cbc(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* iv, uint64_t ivSize, const void* srcBuffer,
                          uint64_t srcBufferSize);

// AES-128 CBC Encrypt - returns srcBufferSize
uint64_t EncryptAes128Cbc(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* iv, uint64_t ivSize, const void* srcBuffer,
                          uint64_t srcBufferSize);

// AES-128 CTR Decrypt - returns srcBufferSize
uint64_t DecryptAes128Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t DecryptAes128CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-128 CTR Encrypt - returns srcBufferSize
uint64_t EncryptAes128Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t EncryptAes128CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-192 CTR Decrypt - returns srcBufferSize
uint64_t DecryptAes192Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t DecryptAes192CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-192 CTR Encrypt - returns srcBufferSize
uint64_t EncryptAes192Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t EncryptAes192CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-256 CTR Decrypt - returns srcBufferSize
uint64_t DecryptAes256Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t DecryptAes256CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-256 CTR Encrypt - returns srcBufferSize
uint64_t EncryptAes256Ctr(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                          uint64_t keySize, const void* ctr, uint64_t ctrSize,
                          const void* srcBuffer, uint64_t srcBufferSize);

uint64_t EncryptAes256CtrPartial(void* dstBuffer, uint64_t dstBufferSize, const void* key,
                                 uint64_t keySize, const void* ctr, uint64_t ctrSize,
                                 int64_t partialSize, const void* srcBuffer,
                                 uint64_t srcBufferSize);

// AES-128 CCM Decrypt
uint64_t DecryptAes128Ccm(void*, uint64_t, void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t, uint64_t);

// AES-128 CCM Encrypt
uint64_t EncryptAes128Ccm(void*, uint64_t, void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t, uint64_t);

// AES-128 GCM Decrypt
uint64_t DecryptAes128Gcm(void*, uint64_t, void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t);

// AES-128 GCM Encrypt
uint64_t EncryptAes128Gcm(void*, uint64_t, void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t);

// AES-256 GCM Decrypt
uint64_t DecryptAes256Gcm(void* dstBuffer, uint64_t dstBufferSize, void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t);

// AES-256 GCM Encrypt
uint64_t EncryptAes256Gcm(void* dstBuffer, uint64_t dstBufferSize, void*, uint64_t, const void*,
                          uint64_t, const void*, uint64_t, const void*, uint64_t, const void*,
                          uint64_t);

namespace detail {
class Md5Impl {
public:
    void Initialize();
    void Update(void const*, uint64_t dataSize);
    void ProcessBlock();
    void GetHash(void*, uint64_t hashSize);
    void ProcessLastBlock();

    uint32_t _x0;
    uint32_t _x4;
    uint32_t _x8;
    uint32_t _xC;
    uint8_t _x10[0x50 - 0x10];
    uint64_t _x50;
    uint32_t _x58;
};

class Sha1Impl {
public:
    void Initialize();
    void Update(void const*, uint64_t);
    void ProcessBlock(void const*);
    void GetHash(void* destHash, uint64_t);
    void ProcessLastBlock();

    void* filler[13];
    uint32_t _68;
};

class Sha256Impl {
public:
    void Initialize();
    void Update(void const*, uint64_t);
    void ProcessBlocks(uint8_t const*, uint64_t);
    void GetHash(void* destHash, uint64_t);
    void ProcessLastBlock();
    void InitializeWithContext(nn::crypto::Sha256Context const*);
    void GetContext(nn::crypto::Sha256Context*) const;

    uint64_t _x0;
    uint64_t _x8;
    uint32_t _x10;
    __uint128_t _x14;
    __uint128_t _x24;
    __uint128_t _x34;
    uint32_t _x44;
    uint64_t _x48;
    uint64_t _x50;
    uint64_t _x58;
    uint64_t _x60;
    uint64_t _x68;
    uint32_t _x70;
};
}  // namespace detail
}  // namespace nn::crypto
