#pragma once

namespace cc {
	
	class SelectEngine : noncopyable
	{
	public:
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		void runStart();
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
			} else if ( 0 == strcmp(startName(), nName) ) {
				nSerialize.runNumbers<vector<int32_t>, int32_t>(mStartIds, "startIds", "startId");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * startName();
		const char * startUrl();
		
		static SelectEngine& instance();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		void runInit();
		void runClear();
		
		SelectEngine();
		~SelectEngine();
		
	private:
		map<int32_t, IfSelectPtr> mIfSelects;
		
		vector<int32_t> mStartIds;
		
		static SelectEngine mSelectEngine;
	};
	
}
