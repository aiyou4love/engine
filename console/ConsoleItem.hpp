#pragma once

namespace cc {
	
	class ConsoleItem : noncopyable
	{
	public:
		const char * getMethod();
		const char * getSwitch();
		const char * getText();
		const char * getName();
		int8_t getType();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mMethod, "method");
			nSerialize->runNumber(mSwitch, "switch");
			nSerialize->runNumber(mType, "type");
			nSerialize->runNumber(mName, "name");
			nSerialize->runNumber(mText, "text");
			nSerialize->runNumber(mIndex, "index");
		}
		
		bool isDefault();
		int16_t getKey();
		
		ConsoleItem();
		~ConsoleItem();
		
	private:
		string mMethod;
		string mSwitch;
		int8_t mType;
		string mName;
		string mText;
		int16_t mIndex;
	};
	typedef SPTR<ConsoleItem> ConsoleItemPtr;
	
}
