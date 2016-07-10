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
			nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelects");
		}
		const char * streamName();
		const char * streamUrl();
		
		static SelectEngine& instance();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		
		SelectEngine();
		~SelectEngine();
		
	private:
		map<int32_t, IfSelectPtr> mIfSelects;
		
		static SelectEngine mSelectEngine;
	};
	
}
