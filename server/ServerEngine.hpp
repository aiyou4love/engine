#pragma once

namespace cc {
	
	class ServerEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, ServerItemPtr>(mServerItems, "serverItems", "serverItem");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		static ServerEngine& instance();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runSave();
		void runClear();
		
		ServerEngine();
		~ServerEngine();
		
	private:
		map<int32_t, ServerItemPtr> mServerItems;
		
		int64_t mUpdateTime;
		
		static ServerEngine mServerEngine;
	};
	
}
