/**
 * @brief Account service implementation.
 */

#pragma once

#include "os.h"

namespace nn::account {
struct Nickname {
    char m_Buffer[0x21];
};
struct NetworkServiceAccountId {
    uint64_t m_Id;
};

class AsyncContext;

class Uid {
public:
    bool IsValid() const { return m_Storage[0] != 0 || m_Storage[1] != 0; }

    uint64_t m_Storage[2];
};

class UserHandle {
public:
    Uid m_Uid;
    void* m_Handle;
};

void Initialize();
Result ListAllUsers(int32_t*, Uid*, int32_t numUsers);
Result OpenUser(UserHandle*, Uid const&);
Result IsNetworkServiceAccountAvailable(bool* out, UserHandle const&);
void CloseUser(UserHandle const&);

Result EnsureNetworkServiceAccountAvailable(UserHandle const& userHandle);
Result EnsureNetworkServiceAccountIdTokenCacheAsync(AsyncContext*, UserHandle const&);
Result LoadNetworkServiceAccountIdTokenCache(uint64_t*, char*, uint64_t, UserHandle const&);

Result GetLastOpenedUser(Uid*);
Result GetNickname(Nickname* nickname, Uid const& userID);
Result GetNetworkServiceAccountId(NetworkServiceAccountId*, const UserHandle&);

Result GetUserId(Uid* uid, const UserHandle& handle);
Result OpenPreselectedUser(UserHandle* handle);

class AsyncContext {
public:
    AsyncContext();
    ~AsyncContext();

    Result HasDone(bool*);
    Result GetResult();
    Result Cancel();
    Result GetSystemEvent(nn::os::SystemEvent*);
};
}  // namespace nn::account
