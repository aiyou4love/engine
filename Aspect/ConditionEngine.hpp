#pragma once

namespace cc {
	
	class ConditionEngine : noncopyable
	{
	public:
		void runDoing(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		void run
		
	public:
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, ConditionPtr>(mConditions, "conditions", "condition");
		}
		const char * streamName();
		const char * streamUrl();
		
		ConditionEngine& instance();
		
		void runPreinit();
		void runLoad();
		
		ConditionEngine();
		~ConditionEngine();
		
	private:
		map<int32_t, ConditionPtr> mConditions;
		
		static ConditionEngine mConditionEngine;
	};
	
}
