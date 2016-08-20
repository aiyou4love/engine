#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerList : noncopyable
	{
	public:
		void getServerItems(list<cServerItemPtr>& nServerItems, int16_t nPageId, int16_t nPageCount);
		
		void pushServerItems(list<cServerItemPtr>& nServerItems);
		void pushServerItem(cServerItem& nServerItem);
		
		cServerItemPtr& getServerItem(int32_t nServerId);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, cServerItemPtr>(mServerItems, "serverItems", "serverItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		void runClear();
		
		bool isLoad();
		
		cServerList();
		~cServerList();
		
	private:
		map<int32_t, cServerItemPtr> mServerItems;
	};
	typedef SPTR<cServerList> cServerListPtr;
#endif
	
}
