#include "../../Engine.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cServerList::getServerItems(list<cServerItemPtr>& nServerItems, int16_t nPageId, int16_t nPageCount)
	{
		int32_t serverId_ = 0;
		int32_t startId_ = (nPageId - 1) * nPageCount;
		int32_t endId_ = nPageId * nPageCount;
		auto it = mServerItems.begin();
		for ( ; it != mServerItems.end(); ++it ) {
			serverId_++;
			cServerItemPtr& serverItem_ = it->second;
			if (serverId_ <= startId_) {
				continue;
			}
			if (serverId_ > endId_) {
				break;
			}
			nServerItems.push_back(serverItem_);
		}
	}
	
	void cServerList::pushServerItems(list<cServerItemPtr>& nServerItems)
	{
		auto it = nServerItems.begin();
		for ( ; it != nServerItems.end(); ++it ) {
			cServerItemPtr& serverItem_ = (*it);
			int32_t serverId_ = serverItem_->getServerId();
			mServerItems[serverId_] = serverItem_;
		}
	}
	
	void cServerList::pushServerItem(ServerItem& nServerItem)
	{
		cServerItemPtr serverItem_(new ServerItem(nServerItem));
		int32_t serverId_ = serverItem_->getServerId();
		mServerItems[serverId_] = serverItem_;
	}
	
	cServerItemPtr& cServerList::getServerItem(int32_t nServerId)
	{
		auto it = mServerItems.find(nServerId);
		if ( it == mServerItems.end() ) {
			LOGE("[%s]", __METHOD__);
			return defaultPtr<ServerItem>();
		}
		return it->second;
	}
	
	void cServerList::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cServerList *>(this, streamUrl(), streamName());
	}
	
	void cServerList::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cServerList *>(this, streamUrl(), streamName());
	}
	
	void cServerList::runClear()
	{
		mServerItems.clear();
	}
	
	bool cServerList::isLoad()
	{
		return (mServerItems.size() > 0);
	}
	
	const char * cServerList::streamName()
	{
		return "serverList";
	}
	
	const char * cServerList::streamUrl()
	{
		return "serverList.json";
	}
	
	cServerList::cServerList()
	{
		mServerItems.clear();
	}
	
	cServerList::~cServerList()
	{
		mServerItems.clear();
	}
#endif
	
}
