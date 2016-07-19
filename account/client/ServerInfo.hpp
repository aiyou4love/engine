#pragma once

namespace cc {
	
	class ServerInfo : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mServerStart, "mServerStart");
		}
		
		void setServerInfo(ServerInfo& nServerInfo);
		
		int64_t getServerStart();
		
		ServerInfo();
		ServerInfo(ServerInfo& nServerInfo);
		~ServerInfo();
		
	private:
		int64_t mServerStart;
	};
	typedef boost::shared_ptr<ServerInfo> ServerInfoPtr;
	
}
