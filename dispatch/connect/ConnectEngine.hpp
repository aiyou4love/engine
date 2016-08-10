#pragma once

namespace cc {
	
	class ConnectEngine : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runMapStreamPtrs<int32_t, IfSelectPtr>(mIfSelects, "ifSelects", "ifSelect");
		}
		const char * streamName();
		const char * streamUrl();
		
		static ConnectEngine& instance();
		
		ConnectEngine();
		~ConnectEngine();
		
	private:
		static ConnectEngine mConnectEngine;
	};
	
}
