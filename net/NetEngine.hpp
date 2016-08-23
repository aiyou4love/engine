#pragma once

namespace cc {
	
	class NetEngine : noncopyable
	{
	public:
		void runSend(int16_t nAppType, EntityPtr& nEntity, ValuePtr& nValue);
		
		static NetEngine& instance();
		
		NetEngine();
		~NetEngine();
		
	private:
		static NetEngine mNetEngine;
	};
	
}
