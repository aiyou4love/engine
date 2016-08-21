#pragma once

#include "../common/Common.hpp"

#include "aspect/doing/Doing.hpp"

#include "aspect/entity/Property.hpp"
#include "aspect/entity/Entity.hpp"

#include "aspect/condition/Condition.hpp"
#include "aspect/condition/ConditionEngine.hpp"

#include "aspect/reward/Reward.hpp"
#include "aspect/reward/RewardEngine.hpp"

#include "aspect/select/Selector.hpp"
#include "aspect/select/IfSelect.hpp"
#include "aspect/select/SelectStart.hpp"
#include "aspect/select/SelectEngine.hpp"

#include "aspect/aspect/IAspect.hpp"
#include "aspect/aspect/AspectEngine.hpp"

#include "dispatch/send/ISend.hpp"
#include "dispatch/dispatch/IDispatch.hpp"

#include "application/Application.hpp"
#include "application/ApplicationDispatch.hpp"
#include "application/ApplicationEngine.hpp"

#include "dispatch/ioservice/IoService.hpp"
#include "dispatch/session/Session.hpp"
#include "dispatch/connect/ConnectInfo.hpp"
#include "dispatch/connect/ConnectIp.hpp"
#include "dispatch/connect/ConnectSession.hpp"
#include "dispatch/connect/Connector.hpp"
#include "dispatch/connect/ConnectEngine.hpp"
#include "dispatch/accept/AcceptIp.hpp"
#include "dispatch/accept/SessionMgr.hpp" 
#include "dispatch/accept/AcceptEngine.hpp"

#include "ui/IUiEngine.hpp"
#include "ui/UiManager.hpp"

#include "console/CommandArgs.hpp"
#include "console/CommandBat.hpp"
#include "console/ConsoleInput.hpp"
#include "console/ConsoleUpdate.hpp"
#include "console/ConsoleItem.hpp"
#include "console/ConsoleUi.hpp"
#include "console/ConsoleEngine.hpp"

#include "account/account/Account.hpp"
#include "account/account/AccountEngine.hpp"

#include "account/client/agent/cServerInfo.hpp"
#include "account/client/agent/cAgentResult.hpp"
#include "account/client/agent/cAgentInfo.hpp"

#include "account/client/serverList/cServerItem.hpp"
#include "account/client/serverList/cServerList.hpp"
#include "account/client/roleList/cRoleItem.hpp"
#include "account/client/roleList/cRoleResult.hpp"
#include "account/client/roleList/cRoleList.hpp"
#include "account/client/login/cLoginResult.hpp"
#include "account/client/account/cAccount.hpp"
#include "account/client/account/cAccountEngine.hpp"
	

extern void engineStart();
extern void engineStop();
