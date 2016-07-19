#include "../../Engine.hpp"

namespace cc {
	
	const char * UrlValue::getUrlValue()
	{
		return mUrlValue.c_str();
	}
	
	const char * UrlValue::getUrlBody()
	{
		return mUrlBody.c_str();
	}
	
	int8_t UrlValue::getUrlType()
	{
		return mUrlType;
	}
		
	int16_t UrlValue::getTimeout()
	{
		return mTimeout;
	}
	
	bool UrlValue::isDefault()
	{
		return ( (0 == mUrlId) || ("" == mUrlValue) );
	}
	
	int8_t UrlValue::getKey()
	{
		return mUrlId;
	}
	
	UrlValue::UrlValue()
		: mUrlId (0)
		, mUrlValue ("")
		, mTimeout (10)
		, mUrlBody ("")
		, mUrlType (0)
	{
	}
	
	UrlValue::~UrlValue()
	{
		mUrlId = 0;
		mUrlValue = "";
		mUrlBody = "";
		mTimeout = 10;
		mUrlType = 0;
	}
	
}
