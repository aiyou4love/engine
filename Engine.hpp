#pragma once

#include "../common/Common.hpp"

#include "random/RandomEngine.hpp"

#include "aspect/doing/EdoingState.hpp"
#include "aspect/doing/Doing.hpp"

#include "aspect/select/SelectState.hpp"

#include "aspect/entity/Entity.hpp"

#include "aspect/condition/Condition.hpp"
#include "aspect/condition/ConditionEngine.hpp"

#include "aspect/reward/Reward.hpp"
#include "aspect/reward/RewardEngine.hpp"

#include "aspect/select/Selector.hpp"
#include "aspect/select/IfSelect.hpp"
#include "aspect/select/SelectEngine.hpp"

#include "aspect/select/SelectEngine.hpp"

#include "aspect/aspect/IAspect.hpp"

#include "account/account/RoleItem.hpp"
#include "account/account/ServerItem.hpp"
#include "account/account/ServerList.hpp"
#include "account/account/Account.hpp"
#include "account/account/AccountEngine.hpp"

#include "account/client/ServerInfo.hpp"
#include "account/client/cRoleList.hpp"
#include "account/client/LoginResult.hpp"
#include "account/client/AgentResult.hpp"
#include "account/client/RoleResult.hpp"
#include "account/client/UrlValue.hpp"
#include "account/client/UrlValue.hpp"
#include "account/client/cAccount.hpp"
#include "account/client/cAccountEngine.hpp"


#include "ui/UiEngine.hpp"

#include "console/ConsoleItem.hpp"
#include "console/ConsoleUi.hpp"
#include "console/ConsoleEngine.hpp"

extern void engineStart();
extern void engineStop();
