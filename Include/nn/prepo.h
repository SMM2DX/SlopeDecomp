#pragma once

#include "account.h"

namespace nn::prepo {

namespace detail {
class PlayReportGenerator {
public:
    PlayReportGenerator() = default;
    void Initialize();

private:
    void* m_Data = nullptr;
};
}  // namespace detail

enum class TransmissionStatus {};

class PlayReport {
public:
    PlayReport();
    explicit PlayReport(const char* event_id);

    Result SetEventId(const char* event_id);
    void SetBuffer(void* buffer, size_t size);
    void Clear();

    Result Add(const char* key, int64_t value);
    Result Add(const char* key, double value);
    Result Add(const char* key, const char* value);

    Result Save();
    Result Save(const account::Uid& uid);

    int32_t GetCount() const;

    static uint32_t CalcBufferSize(int32_t num_entries) { return (size_t(0x82) * num_entries) + 3; }

private:
    char m_EventId[32];
    void* m_Buffer;
    size_t m_BufferSize;
    detail::PlayReportGenerator m_Generator;
};

void Initialize();

Result RequestImmediateTransmission();
Result GetTransmissionStatus(TransmissionStatus* status);

Result ClearStorage();
Result SetOperationMode(int64_t mode);
Result IsUserAgreementCheckEnabled(bool* enabled);
Result SetUserAgreementCheckEnabled(bool enabled);
Result GetStorageUsage(int64_t*, int64_t*);

}  // namespace nn::prepo
