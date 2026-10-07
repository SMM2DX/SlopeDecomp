#pragma once

#include <netdb.h>
#include "nn_Result.h"
#include "util.h"
#include <poll.h>
#include <sys/select.h>
#include <sys/socket.h>

namespace nn {
class TimeSpan;
namespace socket {
struct ResourceStatistics;

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
struct InAddr {
    uint32_t addr;
};
#endif

// taken from https://switchbrew.org/wiki/Sockets_services#BsdBufferConfig
struct BsdBufferConfig {
    size_t tcp_tx_buf_size =
        0x8000;  ///< Size of the TCP transfer (send) buffer (initial or fixed).
    size_t tcp_rx_buf_size = 0x10000;  ///< Size of the TCP recieve buffer (initial or fixed).
    size_t tcp_tx_buf_max_size =
        0x30000;  ///< Maximum size of the TCP transfer (send) buffer. If it is 0, the size of the
                  ///< buffer is fixed to its initial value.
    size_t tcp_rx_buf_max_size =
        0x30000;  ///< Maximum size of the TCP receive buffer. If it is 0,
                  ///< the size of the buffer is fixed to its initial value.
    size_t udp_tx_buf_size =
        0x2400;  ///< Size of the UDP transfer (send) buffer (typically 0x2400 bytes).
    size_t udp_rx_buf_size = 0xA500;  ///< Size of the UDP receive buffer (typically 0xA500 bytes).
    int sb_efficiency =
        4;  ///< Number of buffers for each socket (standard values range from 1 to 8).
};

struct Config {
    int unkInt1 = 2;  // 0x0 (value is 2 in SMO sdk, 8 in sv. could be BsdBufferConfig's version)
    bool unkBool1 = false;         // 0x4
    bool isUseBsdS = false;        // 0x5
    void* pool;                    // 0x8
    size_t poolSize;               // 0x10
    size_t allocPoolSize;          // 0x18
    BsdBufferConfig bufferConfig;  // 0x20-0x50
    int concurLimit;               // 0x54
    int padding;
};

static_assert(sizeof(Config) == 0x60, "Config Size");

int32_t Recv(int32_t socket, void* out, size_t outLen, int32_t flags);
int32_t RecvFrom(int, void*, size_t, int, sockaddr*, uint32_t*);
int32_t Send(int32_t socket, const void* data, size_t dataLen, int32_t flags);
int32_t SendTo(int, const void*, size_t, int, const sockaddr*, uint32_t);
int32_t Accept(int, sockaddr*, uint32_t*);
int32_t Bind(int, const sockaddr*, uint32_t);
nn::Result Connect(int32_t socket, const sockaddr* address, uint32_t addressLen);
int32_t GetPeerName(int, sockaddr*, uint32_t*);
int32_t GetSockName(int, sockaddr*, uint32_t*);
int32_t GetSockOpt(int, int, int, void*, uint32_t*);
int32_t Listen(int, int);
int32_t SetSockOpt(int32_t socket, int32_t socketLevel, int32_t option, const void*, uint32_t len);
int32_t SockAtMark(int);
int32_t Shutdown(int, int);
int32_t ShutdownAllSockets(bool);
int32_t Socket(int32_t domain, int32_t type, int32_t protocol);
int32_t SocketExempt(int, int, int);
int32_t Write(int, const void*, size_t);
int32_t Read(int, void*, size_t);
Result Close(int32_t socket);
int32_t Select(int, fd_set*, fd_set*, fd_set*, timeval*);
int32_t Poll(pollfd*, size_t, int);
int32_t Fcntl(int, int, ...);
int32_t InetPton(int, const char*, void*);
const char* InetNtop(int af, const void* src, char* dst, uint32_t size);

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
int32_t InetAton(const char* addressStr, InAddr* addressOut);
char* InetNtoa(InAddr);
#endif

int32_t InetAton(const char* addressStr, in_addr* addressOut);
char* InetNtoa(in_addr);

uint16_t InetHtons(uint16_t val);
uint32_t InetHtonl(uint32_t);
uint16_t InetNtohs(uint16_t);
uint32_t InetNtohl(uint32_t);
int32_t GetLastErrno();
void SetLastErrno(int);
int32_t RecvMsg(int, msghdr*, int);
int32_t RecvMMsg(int, mmsghdr*, size_t, int, nn::TimeSpan*);
int32_t SendMsg(int, const msghdr*, int);
int32_t SendMMsg(int, const mmsghdr*, size_t, int);
int32_t Ioctl(int, uint32_t, void*, size_t);
int32_t Open(const char*, int);
Result Initialize(void* pool, size_t poolSize, size_t allocPoolSize, int concurLimit);
Result Initialize(nn::socket::Config const&);
int32_t Finalize();
int32_t GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**);
int32_t GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**, int);
int32_t GetAddrInfoWithoutNsdResolve(const char*, const char*, const addrinfo*, addrinfo**);
int32_t GetAddrInfoWithoutNsdResolve(const char*, const char*, const addrinfo*, addrinfo**, int);
int32_t FreeAddrInfo(addrinfo*);
int32_t GetNameInfo(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int);
int32_t GetNameInfo(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int, int);
hostent* GetHostByName(const char* name);
hostent* GetHostByName(const char*, int);
hostent* GetHostByNameWithoutNsdResolve(const char*);
hostent* GetHostByNameWithoutNsdResolve(const char*, int);
hostent* GetHostByAddr(const void*, uint32_t, int);
hostent* GetHostByAddr(const void*, uint32_t, int, int);
int32_t RequestCancelHandle();
int32_t Cancel(int);
int32_t GetHErrno();
int32_t HStrError(int);
int32_t GAIStrError(int);
int32_t Sysctl(int*, size_t, void*, size_t*, void*, size_t);
int32_t DuplicateSocket(int, size_t);
int32_t GetResourceStatistics(ResourceStatistics*, size_t);

}  // namespace socket
}  // namespace nn

extern "C" {

int nnsocketRecv(int socket, void* out, size_t outLen, int flags);
int nnsocketRecvFrom(int, void*, size_t, int, sockaddr*, uint32_t*);
int nnsocketSend(int socket, const void* data, size_t dataLen, int flags);
int nnsocketSendTo(int, const void*, size_t, int, const sockaddr*, uint32_t);
int nnsocketAccept(int, sockaddr*, uint32_t*);
int nnsocketBind(int, const sockaddr*, uint32_t);
uint32_t nnsocketConnect();  // returns nn::Result
int nnsocketGetPeerName(int, sockaddr*, uint32_t*);
int nnsocketGetSockName(int, sockaddr*, uint32_t*);
int nnsocketGetSockOpt(int, int, int, void*, uint32_t*);
int nnsocketListen(int, int);
int nnsocketSetSockOpt(int socket, int socketLevel, int option, const void*, uint32_t len);
int nnsocketSockAtMark(int);
int nnsocketShutdown(int, int);
int nnsocketSocket(bool);
int nnsocketWrite(int domain, int type, int protocol);
int nnsocketRead(int, int, int);
uint32_t nnsocketClose();  // returns nn::Result
void nnsocketSelect(int, fd_set*, fd_set*, fd_set*, timeval*);
void nnsocketPoll(pollfd*, size_t, int);
void nnsocketFcntl(int, int, ...);
void nnsocketInetPton(int, const char*, void*);
const char* nnsocketInetNtop(int af, const void* src, char* dst, uint32_t size);
int32_t nnsocketInetAton(const char* addressStr, in_addr* addressOut);
char* nnsocketInetNtoa(in_addr);
uint16_t nnsocketInetHtons(uint16_t val);
uint32_t nnsocketInetHtonl(uint32_t);
uint16_t nnsocketInetNtohs(uint16_t);
uint32_t nnsocketInetNtohl(uint32_t);
int32_t nnsocketGetLastErrno();
void nnsocketSetLastErrno(int);
int32_t nnsocketRecvMsg(int, msghdr*, int);
int32_t nnsocketSendMsg(int, const msghdr*, int);
int32_t nnsocketIoctl(int, uint32_t, void*, size_t);
int32_t nnsocketOpen(const char*, int);
uint32_t nnsocketInitialize(void* pool, size_t poolSize, size_t allocPoolSize, int concurLimit);
int32_t nnsocketFinalize();
int32_t nnsocketGetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**);
int32_t nnsocketGetAddrInfoCancel(const char*, const char*, const addrinfo*, addrinfo**, int);
int32_t nnsocketGetAddrInfoWithoutNsdResolve(const char*, const char*, const addrinfo*, addrinfo**);
int32_t nnsocketGetAddrInfoWithoutNsdResolveCancel(const char*, const char*, const addrinfo*,
                                                   addrinfo**, int);
int32_t nnsocketFreeAddrInfo(addrinfo*);
int32_t nnsocketGetNameInfo(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int);
int32_t nnsocketGetNameInfoCancel(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int,
                                  int);
hostent* nnsocketGetHostByName(const char* name);
hostent* nnsocketGetHostByNameCancel(const char*, int);
hostent* nnsocketGetHostByNameWithoutNsdResolve(const char*);
hostent* nnsocketGetHostByNameWithoutNsdResolveCancel(const char*, int);
hostent* nnsocketGetHostByAddr(const void*, uint32_t, int);
hostent* nnsocketGetHostByAddrCancel(const void*, uint32_t, int, int);
int32_t nnsocketRequestCancelHandle();
int32_t nnsocketCancel(int);
int32_t nnsocketGetHErrno();
int32_t nnsocketHStrError(int);
int32_t nnsocketGAIStrError(int);
int32_t nnsocketSysctl(int*, size_t, void*, size_t*, void*, size_t);
int32_t nnsocketDuplicateSocket(int, size_t);
}
