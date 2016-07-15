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
		}
		
		const char * getUrlValue();
		const char * getUrlName();
		
		bool isDefault();
		string getKey();
		
		UrlValue();
		~UrlValue();
		
	private:
		string mUrlName;
		string mUrlValue;
	};
	typedef boost::shared_ptr<UrlValue> UrlValuePtr;

}
