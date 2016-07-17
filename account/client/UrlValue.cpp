#include "../../Engine.hpp"

namespace cc {
	
	const char * UrlValue::getUrlValue()
	{
		return mUrlValue.c_str();
	}
	
	const char * UrlValue::getUrlName()
	{
		return mUrlName.c_str();
	}
	
	int16_t UrlValue::getTimeout()
	{
		return mTimeout;
	}
	
	bool UrlValue::isDefault()
	{
		return ( ("" == mUrlName) || ("" == mUrlValue) );
	}

	string UrlValue::getKey()
	{
		return mUrlName;
	}
	
	UrlValue::UrlValue()
		: mUrlName ("")
		, mUrlValue ("")
		, mTimeout (10)
	{
	}
	
	UrlValue::~UrlValue()
	{
		mUrlName = "";
		mUrlValue = "";
		mTimeout = 10;
	}
	
}
