#pragma once

namespace cc {
	
	class ServerTime : noncopyable
	{
	public:
		void setFirstStart(int64_t nFirstStart);
		int64_t getFirstStart();
		
		int64_t getStartTime();
		
		void runPreinit();
		
		ServerTime();
		virtual ~ServerTime();
		
	protected:
		int64_t mFirstStart;
		int64_t mStartTime;
		int32_t mTimeDiff;
	};
	
}
