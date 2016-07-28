#pragma once

namespace cc {
	
	class ServerList : noncopyable
	{
	public:
		void pageServers(list<ServerItemPtr>& nServerItems, int16_t nPageId, int16_t nPageCount);
		
		ServerItemPtr& getServerItem(int32_t nServerId);
		
		void pushServerItems(list<ServerItemPtr>& nServerItems);
		void pushServerItem(ServerItem& nServerItem);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			LOGF;
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "serverItems", "serverItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		bool isLoad();
		
		ServerList();
		~ServerList();
		
	private:
		map<int32_t, ServerItemPtr> mServerItems;
	};
	typedef std::shared_ptr<ServerList> ServerListPtr;
	
}
