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
	{
	}
	
	UrlValue::~UrlValue()
	{
		mUrlName = "";
		mUrlValue = "";
	}
	
}
