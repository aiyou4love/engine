#pragma once

namespace cc {
	
	class NetEngine : noncopyable
	{
	public:
		void initNet(EntityPtr& nEntity, ConnectInfo& nConnectInfo);
		void sendNet(EntityPtr& nEntity, ValuePtr& nValue);
		
		static NetEngine& instance();
		
		NetEngine();
		~NetEngine();
		
	private:
		static NetEngine mNetEngine;
	};
	
}
