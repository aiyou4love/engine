#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cServerInfo : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mServerStart, "mServerStart");
		}
		
		void setServerInfo(cServerInfo& nServerInfo);
		
		int64_t getServerStart();
		
		cServerInfo();
		cServerInfo(cServerInfo& nServerInfo);
		~cServerInfo();
		
	private:
		int64_t mServerStart;
	};
	typedef SPTR<cServerInfo> cServerInfoPtr;
#endif
	
}
