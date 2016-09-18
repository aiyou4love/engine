#pragma once

namespace cc {
	
	class ServerTime : noncopyable
	{
	public:
		void runPreinit();
		
		ServerTime();
		virtual ~ServerTime();
		
	protected:
		int32_t mTimeDiff;
	};
	
}
