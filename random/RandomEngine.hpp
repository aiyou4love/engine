#pragma once

namespace cc {
	
	class RandomEngine : noncopyable
	{
	public:
		int32_t runRandom(int32_t nMin, int32_t nMax);
		int32_t runRandom(int32_t nValue);
		static RandomEngine& instance();
		
		void runPreinit();
		
		RandomEngine();
		~RandomEngine();
		
	private:
		static RandomEngine mRandomEngine;
		
		random_device mDevice;
		mt19937 mEngine;
	};
	
}
