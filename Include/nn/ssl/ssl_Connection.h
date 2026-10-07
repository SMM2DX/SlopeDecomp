#pragma once

#include "ssl/ssl_Context.h"

namespace nn::ssl {

// @nncbindgen
class Connection {
public:
    // @nncbindgen(memberof=Connection)
    enum class VerifyOption {
        PeerCa = 1 << 0,
        HostName = 1 << 1,
        DateCheck = 1 << 2,
        EvCertPartial = 1 << 3,
        EvPolicyOid = 1 << 4,        // [6.0.0+]
        EvCertFingerprint = 1 << 5,  // [6.0.0+]
    };

    // @nncbindgen(memberof=Connection)
    enum class IoMode { Blocking = 1, NonBlocking = 2 };

    // @nncbindgen(memberof=Connection)
    enum class SessionCacheMode { None, SessionId, SessionTicket };

    enum class RenegotiationMode { None, Secure };

    // @nncbindgen(memberof=Connection)
    enum class PollEvent { Read = 1 << 0, Write = 1 << 1, Except = 1 << 2 };

    // @nncbindgen(memberof=Connection)
    enum class OptionType {
        DoNotCloseSocket,
        GetServerCertChain,  // [3.0.0+]
        SkipDefaultVerify,   // [5.0.0+]
        EnableAlpn,          // [9.0.0+]
    };

    // @nncbindgen(memberof=Connection)
    struct ServerCertDetail {};

    Connection();
    ~Connection();

    // @nncbindgen(memberof=Connection)
    nn::Result Create(Context* context);
    // @nncbindgen(memberof=Connection)
    nn::Result Destroy();
    // @nncbindgen(memberof=Connection)
    nn::Result SetSocketDescriptor(int32_t socketDescriptor);
    // @nncbindgen(memberof=Connection)
    nn::Result SetHostName(const char* hostName, uint32_t hostNameSize);
    // @nncbindgen(memberof=Connection)
    nn::Result SetVerifyOption(nn::ssl::Connection::VerifyOption verifyOption);
    // @nncbindgen(memberof=Connection)
    nn::Result SetServerCertBuffer(const char* serverCertificateBuffer,
                                   uint32_t serverCertificateBufferSize);
    // @nncbindgen(memberof=Connection)
    nn::Result SetIoMode(nn::ssl::Connection::IoMode ioMode);
    // @nncbindgen(memberof=Connection)
    nn::Result SetSessionCacheMode(nn::ssl::Connection::SessionCacheMode sessionCacheMode);
    Result SetRenegotiationMode(RenegotiationMode renegotiationMode);
    // @nncbindgen(memberof=Connection)
    nn::Result GetSocketDescriptor(int32_t* outSocketDescriptor);
    // @nncbindgen(memberof=Connection)
    nn::Result GetHostName(const char* outHostName, uint32_t* outHostNameSize,
                           uint32_t maxHostNameSize);
    // @nncbindgen(memberof=Connection)
    nn::Result GetVerifyOption(nn::ssl::Connection::VerifyOption* outVerifyOption);
    // @nncbindgen(memberof=Connection)
    nn::Result GetIoMode(nn::ssl::Connection::IoMode* outIoMode);
    Result GetSessionCacheMode(SessionCacheMode* outSessionCacheMode);
    Result GetRenegotiationMode(RenegotiationMode* outRenegotiationMode);
    Result FlushSessionCache();
    // @nncbindgen(memberof=Connection)
    nn::Result DoHandshake();
    // @nncbindgen(memberof=Connection,rename=DoHandshakeWithCertBuffer)
    nn::Result DoHandshake(uint32_t* outServerCertificateBufferSize, uint32_t* outNumCertificates);
    // @nncbindgen(memberof=Connection,rename=DoHandshakeWithBuffer)
    nn::Result DoHandshake(uint32_t* outServerCertificateBufferSize, uint32_t* outNumCertificates,
                           char* outServerCertificateBuffer,
                           uint32_t serverCertificateBufferMaxSize);
    // @nncbindgen(memberof=Connection)
    nn::Result GetServerCertDetail(nn::ssl::Connection::ServerCertDetail*, const char*, uint32_t);
    Result Read(char* outBuffer, uint32_t maxBufferSize);
    // @nncbindgen(memberof=Connection)
    nn::Result Read(char* outBuffer, int32_t* outBufferSize, uint32_t maxBufferSize);
    Result Write(const char* buffer, uint32_t maxBufferSize);
    // @nncbindgen(memberof=Connection)
    nn::Result Write(const char* buffer, int32_t* outWrittenBufferSize, uint32_t maxBufferSize);
    Result Pending();
    // @nncbindgen(memberof=Connection)
    nn::Result Pending(int32_t*);
    // @nncbindgen(memberof=Connection)
    nn::Result Peek(char* outBuffer, int32_t* outBufferSize, uint32_t maxBufferSize);
    // @nncbindgen(memberof=Connection)
    nn::Result Poll(nn::ssl::Connection::PollEvent*, nn::ssl::Connection::PollEvent*,
                    uint32_t timeout);
    Result GetLastError(Result* outErrorResult);
    // @nncbindgen(memberof=Connection)
    nn::Result GetVerifyCertError(nn::Result* outErrorResult);
    Result GetVerifyCertErrors(Result* outErrorResults, uint32_t*, uint32_t*,
                               uint32_t maxErrorResultCount);
    Result GetNeededServerCertBufferSize(uint32_t* outNeededServerCertBufferSize);
    // @nncbindgen(memberof=Connection)
    nn::Result GetContextId(uint64_t* outContextId);
    // @nncbindgen(memberof=Connection)
    nn::Result GetConnectionId(uint64_t* outConnectionId);
    // @nncbindgen(memberof=Connection)
    nn::Result SetOption(nn::ssl::Connection::OptionType option, bool value);
    // @nncbindgen(memberof=Connection)
    nn::Result GetOption(bool* outValue, nn::ssl::Connection::OptionType option);

private:
    uint64_t mConnectionId;
    uint64_t mContextId;
    unsigned char _10[8];
    const char* mServerCertificateBuffer;
    uint32_t mServerCertificateBufferSize;
    Result _24;
};
}  // namespace nn::ssl
