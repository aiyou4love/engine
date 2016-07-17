#pragma once

namespace cc {
	
	class ConsoleItem : noncopyable
	{
	public:
		const char * getLuaMethod();
		const char * getText();
		bool isGlob();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			LOGF;
			
			nSerialize->runNumber(mLuaMethod, "luaMethod");
			nSerialize->runNumber(mIndex, "index");
			nSerialize->runNumber(mText, "text");
			nSerialize->runNumber(mIsGlob, "isGlob");
		}
		
		int16_t getKey();
		
		ConsoleItem();
		~ConsoleItem();
				
	private:
		string mLuaMethod;
		int16_t mIndex;
		string mText;
		bool mIsGlob;
	};
	typedef boost::shared_ptr<ConsoleItem> ConsoleItemPtr;
	
}
