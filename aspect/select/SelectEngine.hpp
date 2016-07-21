#pragma once

namespace cc {
	
	class SelectEngine : noncopyable
	{
	public:
		void runIfSelect(int32_t nIfSelectId, EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			LOGF;
			
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
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
		
		SelectEngine();
		~SelectEngine();
		
	private:
		map<int32_t, IfSelectPtr> mIfSelects;
		list<int32_t> mSelectStarts;
		
		static SelectEngine mSelectEngine;
	};
	
}
