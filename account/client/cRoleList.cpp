#include "../../Engine.hpp"

namespace cc {
		
	RoleItemPtr cRoleList::getRoleItem(int32_t nServerId, int32_t nRoleId)
	{
		int64_t id_ = nServerId;
		 id_ <<= 32;
		 id_ |= nRoleId;
		auto it = mRoleItems.find(id_);
		if ( it == mRoleItems.end() ) {
			LOGE("[%s]", __METHOD__);
			return defaultValue<RoleItemPtr>();
		}
		return it->second;
	}
	
	void cRoleList::pushRoleItems(list<RoleItemPtr>& nRoleItems)
	{
		auto it = nRoleItems.begin();
		for ( ; it != nRoleItems.end(); ++it ) {
			RoleItemPtr& roleItem_ = (*it);
			mRoleItems[roleItem_->getId()] = roleItem_;
		}
	}
	
	void cRoleList::pushRoleItem(RoleItem& nRoleItem)
	{
		RoleItemPtr roleItem_(new RoleItem(nRoleItem));
		mRoleItems[roleItem_->getId()] = roleItem_;
	}
	
	map<int64_t, RoleItemPtr>& cRoleList::getRoleItems()
	{
		return mRoleItems;
	}
	
	void cRoleList::runClear()
	{
		mRoleItems.clear();
	}
	
	cRoleList::cRoleList()
	{
		mRoleItems.clear();
	}
	
	cRoleList::~cRoleList()
	{
		mRoleItems.clear();
	}
	
}
