#pragma once

namespace cc {
	
	class UrlValue : noncopyable
	{
	public:
		template<class T>
		void serialize(T nSerialize, const char * nName)
		{
			nSerialize->runNumber(mUrlName, "urlName");
			nSerialize->runNumber(mUrlValue, "urlValue");
			nSerialize->runNumber(mTimeout, "timeout");
		}
		
		const char * getUrlValue();
		const char * getUrlName();
		int16_t getTimeout();
		
		bool isDefault();
		string getKey();
		
		UrlValue();
		~UrlValue();
		
	private:
		string mUrlName;
		string mUrlValue;
		int16_t mTimeout;
	};
	typedef boost::shared_ptr<UrlValue> UrlValuePtr;

}
