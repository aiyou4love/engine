#include "../../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	cRoleItemPtr& cRoleList::getRoleItem(int32_t nServerId, int32_t nRoleId)
	{
		int64_t id_ = nServerId;
		 id_ <<= 32;
		 id_ |= nRoleId;
		auto it = mRoleItems.find(id_);
		if ( it == mRoleItems.end() ) {
			LOGE("[%s]", __METHOD__);
			return defaultPtr<cRoleItem>();
		}
		return it->second;
	}
	
	void cRoleList::pushRoleItems(list<cRoleItemPtr>& nRoleItems)
	{
		auto it = nRoleItems.begin();
		for ( ; it != nRoleItems.end(); ++it ) {
			cRoleItemPtr& roleItem_ = (*it);
			mRoleItems[roleItem_->getId()] = roleItem_;
		}
	}
	
	void cRoleList::pushRoleItem(cRoleItem& nRoleItem)
	{
		cRoleItemPtr roleItem_(new cRoleItem(nRoleItem));
		mRoleItems[roleItem_->getId()] = roleItem_;
	}
	
	map<int64_t, cRoleItemPtr>& cRoleList::getRoleItems()
	{
		return mRoleItems;
	}
	
	const char * cRoleList::streamName()
	{
		return "roleList";
	}
	
	const char * cRoleList::streamUrl()
	{
		return "roleList.json";
	}
	
	void cRoleList::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cRoleList *>(this, streamUrl(), streamName());
	}
	
	void cRoleList::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cRoleList *>(this, streamUrl(), streamName());
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
#endif
	
}
