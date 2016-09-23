#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void RoleEngine::pushRoleItem(RoleItemPtr& nRoleItem)
	{
		if ( nRoleItem->isDefault() ) {
			return;
		}
		int64_t id_ = nRoleItem->getId();
		mRoleItems[id_] = nRoleItem;
	}
	
	const char * RoleEngine::streamName()
	{
		return "roleEngine";
	}
	
	const char * RoleEngine::streamUrl()
	{
		return "roleEngine.json";
	}
	
	void RoleEngine::runPreinit()
	{
	}
	
	void RoleEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<RoleEngine *>(this, streamUrl(), streamName());
	}
	
	void RoleEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<RoleEngine *>(this, streamUrl(), streamName());
	}
	
	void RoleEngine::runClear()
	{
		mRoleItems.clear();
	}
	
	RoleEngine::RoleEngine()
	{
		mRoleItems.clear();
	}
	
	RoleEngine::~RoleEngine()
	{
		mRoleItems.clear();
	}
#endif
	
}
