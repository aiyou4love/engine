#pragma once

namespace cc {
	
	class SelectEngine : noncopyable
	{
	public:
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
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
