#pragma once

namespace cc {
	
	class CloseEngine : noncopyable
	{
	public:
		void runDoing(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		
	private:
		bool runCondition(int32_t nId, EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		
	public:
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, ClosedPtr>(mCloseds, "closeds", "closed");
		}
		const char * streamName();
		const char * streamUrl();
		
		CloseEngine& instance();
		
		void runPreinit();
		void runLoad();
		
		CloseEngine();
		~CloseEngine();
		
	private:
		map<int32_t, ClosedPtr> mCloseds;
		
		static CloseEngine mCloseEngine;
	};
	
}
