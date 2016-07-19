#include "../../Engine.hpp"

namespace cc {
	
	void ServerList::pageServers(list<ServerItemPtr>& nServerItems, int16_t nPageId, int16_t nPageCount)
	{
		int32_t serverId_ = 0;
		int32_t startId_ = (nPageId - 1) * nPageCount;
		int32_t endId_ = nPageId * nPageCount;
		auto it = mServerItems.begin();
		for ( ; it != mServerItems.end(); ++it ) {
			serverId_++;
			ServerItemPtr& serverItem_ = it->second;
			if (serverId_ <= startId_) {
				continue;
			}
			if (serverId_ > endId_) {
				break;
			}
			nServerItems.push_back(serverItem_);
		}
		
	}
	
	ServerItemPtr ServerList::getServerItem(int32_t nServerId)
	{
		auto it = mServerItems.find(nServerId);
		if ( it == mServerItems.end() ) {
			LOGE("[%s]", __METHOD__);
			return defaultValue<boost::shared_ptr<ServerItem> >();
		}
		return it->second;
	}
	
	void ServerList::pushServerItems(list<ServerItemPtr>& nServerItems)
	{
		auto it = nServerItems.begin();
		for ( ; it != nServerItems.end(); ++it ) {
			ServerItemPtr& serverItem_ = (*it);
			int32_t serverId_ = serverItem_->getServerId();
			mServerItems[serverId_] = serverItem_;
		}
	}
	
	void ServerList::pushServerItem(ServerItem& nServerItem)
	{
		ServerItemPtr serverItem_(new ServerItem(nServerItem));
		int32_t serverId_ = serverItem_->getServerId();
		mServerItems[serverId_] = serverItem_;
	}
	
	bool ServerList::isLoad()
	{
		return (mServerItems.size() > 0);
	}
	
	ServerList::ServerList()
	{
		mServerItems.clear();
	}
	
	ServerList::~ServerList()
	{
		mServerItems.clear();
	}
	
}
