#pragma once

#include "os_MessageQueueTypes.h"
#include "../time.h"
#include "../util.h"

namespace nn::os {

void InitializeMessageQueue(nn::os::MessageQueueType*, uint64_t* buf, uint64_t queueCount);
void FinalizeMessageQueue(nn::os::MessageQueueType*);

void SendMessageQueue(MessageQueueType*, uint64_t);
bool TrySendMessageQueue(MessageQueueType*, uint64_t);
bool TimedSendMessageQueue(MessageQueueType*, uint64_t, nn::TimeSpan);

void ReceiveMessageQueue(uint64_t* out, MessageQueueType*);
bool TryReceiveMessageQueue(uint64_t* out, MessageQueueType*);
bool TimedReceiveMessageQueue(uint64_t* out, MessageQueueType*, nn::TimeSpan);

void PeekMessageQueue(uint64_t*, const MessageQueueType*);
bool TryPeekMessageQueue(uint64_t*, const MessageQueueType*);
bool TimedPeekMessageQueue(uint64_t*, const MessageQueueType*, nn::TimeSpan);

void JamMessageQueue(nn::os::MessageQueueType*, uint64_t);
bool TryJamMessageQueue(nn::os::MessageQueueType*, uint64_t);
bool TimedJamMessageQueue(nn::os::MessageQueueType*, uint64_t, nn::TimeSpan);

class MessageQueue {
    NN_NO_COPY(MessageQueue);
    NN_NO_MOVE(MessageQueue);

public:
    MessageQueue(uintptr_t* buffer, size_t count) {
        InitializeMessageQueue(&m_MessageQueue, buffer, count);
    }

    ~MessageQueue() { FinalizeMessageQueue(&m_MessageQueue); }

    void Send(uintptr_t data) { SendMessageQueue(&m_MessageQueue, data); }

    bool TrySend(uintptr_t data) { return TrySendMessageQueue(&m_MessageQueue, data); }

    bool TimedSend(uintptr_t data, TimeSpan timeSpan) {
        return TimedSendMessageQueue(&m_MessageQueue, data, timeSpan);
    }

    void Jam(uintptr_t data) { JamMessageQueue(&m_MessageQueue, data); }

    bool TryJam(uintptr_t data) { return TryJamMessageQueue(&m_MessageQueue, data); }

    bool TimedJam(uintptr_t data, TimeSpan timeSpan) {
        return TimedJamMessageQueue(&m_MessageQueue, data, timeSpan);
    }

    void Receive(uintptr_t* outData) { ReceiveMessageQueue(outData, &m_MessageQueue); }

    bool TryReceive(uintptr_t* outData) { return TryReceiveMessageQueue(outData, &m_MessageQueue); }

    bool TimedReceive(uintptr_t* outData, TimeSpan timeSpan) {
        return TimedReceiveMessageQueue(outData, &m_MessageQueue, timeSpan);
    }

    /// XXX: `Peek` functions could be `const`, but according to DWARF from BTD5, they
    /// are not
    void Peek(uintptr_t* outData) { PeekMessageQueue(outData, &m_MessageQueue); }

    bool TryPeek(uintptr_t* outData) { return TryPeekMessageQueue(outData, &m_MessageQueue); }

    bool TimedPeek(uintptr_t* outData, TimeSpan timeSpan) {
        return TimedPeekMessageQueue(outData, &m_MessageQueue, timeSpan);
    }

    operator MessageQueueType&() { return m_MessageQueue; }

    operator const MessageQueueType&() const { return m_MessageQueue; }

    MessageQueueType* GetBase() { return &m_MessageQueue; }

private:
    MessageQueueType m_MessageQueue;
};

}  // namespace nn::os
