#pragma once

namespace cc {
	
	class SelectEngine : noncopyable
	{
	public:
		void runIfSelect(int32_t nIfSelectId, EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
			} else if ( 0 == strcmp(startName(), nName) ) {
				nSerialize.runNumbers<list<int32_t>, int32_t>(mSelectStarts, "selectStarts", "selectStart");
			} else {
				LOGERROR("[%s]%s", __METHOD__, nName);
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
		void runStart();
		
		SelectEngine();
		~SelectEngine();
		
	private:
		map<int32_t, IfSelectPtr> mIfSelects;
		List<int32_t> mSelectStarts;
		
		static SelectEngine mSelectEngine;
	};
	
}
