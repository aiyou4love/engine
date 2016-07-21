#pragma once

namespace cc {
	
	class ServerList : noncopyable
	{
	public:
		void pageServers(list<ServerItemPtr>& nServerItems, int16_t nPageId, int16_t nPageCount);
		
		ServerItemPtr getServerItem(int32_t nServerId);
		
		void pushServerItems(list<ServerItemPtr>& nServerItems);
		void pushServerItem(ServerItem& nServerItem);
		
		bool isLoad();
		
		ServerList();
		~ServerList();
		
	private:
		map<int32_t, ServerItemPtr> mServerItems;
	};
	typedef std::shared_ptr<ServerList> ServerListPtr;
	
}
