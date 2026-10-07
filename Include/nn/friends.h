/**
 * @brief Friend implementation.
 */

#pragma once

#include "account.h"
#include "friends/friends_Types.h"
#include "os.h"

namespace nn::friends {
class AsyncContext;
class Profile;

void Initialize();
Result GetProfileList(nn::friends::AsyncContext* context, nn::friends::Profile* profiles,
                      nn::account::Uid const& userID,
                      nn::account::NetworkServiceAccountId const* accountIDs, int32_t numAccounts);

class Profile {
public:
    Profile();

    nn::account::NetworkServiceAccountId GetAccountId() const;
    nn::account::Nickname& GetNickname() const;
    bool IsValid() const;
    Result GetProfileImageUrl(nn::friends::Url*, ImageSize) const;
};

class AsyncContext {
public:
    AsyncContext();
    ~AsyncContext();

    Result GetSystemEvent(nn::os::SystemEvent*);
    Result GetResult() const;
};
}  // namespace nn::friends
