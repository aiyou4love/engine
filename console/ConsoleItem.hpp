#pragma once

namespace cc {
	
	class ConsoleItem : noncopyable
	{
	public:
		const char * getMethod();
		const char * getText();
		const char * getName();
		int8_t getType();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			LOGF;
			nSerialize->runNumber(mMethod, "method");
			nSerialize->runNumber(mType, "type");
			nSerialize->runNumber(mName, "name");
			nSerialize->runNumber(mText, "text");
			nSerialize->runNumber(mIndex, "index");
		}
		
		int16_t getKey();
		
		ConsoleItem();
		~ConsoleItem();
		
	private:
		string mMethod;
		int8_t mType;
		string mName;
		string mText;
		int16_t mIndex;
	};
	typedef std::shared_ptr<ConsoleItem> ConsoleItemPtr;
	
}
