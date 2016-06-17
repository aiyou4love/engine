#pragma once

namespace std {
	
	class CloseEngine : noncopyable
	{
	public:
		void runDoing(int32_t nId, PlayerPtr& nPlayer, ValuePtr& nValue);
		
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, ClosedPtr>(mCloseds, "closeds", "closed");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runConfig();
		
		static CloseEngine& instance();
		
		CloseEngine();
		~CloseEngine();
		
	private:
		map<int32_t, ClosedPtr> mCloseds;
		static CloseEngine mCloseEngine;
	};
	
}
