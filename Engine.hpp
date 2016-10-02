#pragma once

#include "../common/Common.hpp"

#include "time/time/ServerTime.hpp"
#include "time/time/TimeEngine.hpp"
#include "time/server/cServerTime.hpp"
#include "time/client/cServerTime.hpp"

#include "role/role/RoleItem.hpp"
#include "role/client/cRoleListResult.hpp"
#include "role/client/RoleEngine.hpp"

#include "account/account/Account.hpp"
#include "account/account/AccountEngine.hpp"
#include "account/agent/cAccount.hpp"
#include "account/agent/cAccountEngine.hpp"
#include "account/social/cAccount.hpp"
#include "account/social/cAccountEngine.hpp"
#include "account/client/EaccountId.hpp"
#include "account/client/cRoleResult.hpp"
#include "account/client/cLoginResult.hpp"
#include "account/client/cAccount.hpp"
#include "account/client/cAccountEngine.hpp"

extern void engineStart();
