#pragma once

namespace cc {
	
	class ServerItem : noncopyable
	{
	public:
		void luaValue(LuaWriter * nLuaWriter, const char * nName);
		
		template<class T>
		void serialize(T nSerialize, const char * nName)
		{
			nSerialize->runNumber(mServerId, "mServerId");
			nSerialize->runNumber(mServerName, "mServerName");
			nSerialize->runNumber(mServerNo, "mServerNo");
		}
		
		int32_t getServerId();
        const char * getServerName();
        int16_t getServerNo();
		
		ServerItem();
		ServerItem(ServerItem& nServerItem);
		~ServerItem();
		
	private:
		int32_t mServerId;
        string mServerName;
        int32_t mServerNo;
	};
	typedef std::shared_ptr<ServerItem> ServerItemPtr;
	
}
