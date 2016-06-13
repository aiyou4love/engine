#pragma once

namespace std {
	
	class DoingEngine : noncopyable
	{
	public:
		void runDoing(int32_t nId, PlayerPtr& nPlayer, ValuePtr& nValue);
		
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, DoingMgrPtr>(mDoingMgrs, "doingMgrs", "doingMgr");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runConfig();
		
		static DoingEngine& instance();
		
		DoingEngine();
		~DoingEngine();
		
	private:
		map<int32_t, DoingMgrPtr> mDoingMgrs;
		static DoingEngine mDoingEngine;
	};
	
}
