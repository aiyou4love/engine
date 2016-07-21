#pragma once

namespace cc {
	
	class UrlValue : noncopyable
	{
	public:
		template<class T>
		void serialize(T nSerialize, const char * nName)
		{
			nSerialize->runNumber(mUrlId, "urlName");
			nSerialize->runNumber(mUrlValue, "urlValue");
			nSerialize->runNumber(mUrlType, "urlType");
			nSerialize->runNumber(mUrlBody, "urlBody");
			nSerialize->runNumber(mTimeout, "timeout");
		}
		
		const char * getUrlValue();
		const char * getUrlBody();
		int16_t getTimeout();
		int8_t getUrlType();
		
		bool isDefault();
		int8_t getKey();
		
		UrlValue();
		~UrlValue();
		
	private:
		int8_t mUrlId;
		string mUrlValue;
		int8_t mUrlType;
		string mUrlBody;
		int16_t mTimeout;
	};
	typedef std::shared_ptr<UrlValue> UrlValuePtr;
	
}
