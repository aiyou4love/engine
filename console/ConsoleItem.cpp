#include "../Engine.hpp"

namespace cc {
	
	const char * ConsoleItem::getSwitch()
	{
		return mSwitch.c_str();
	}
	
	const char * ConsoleItem::getMethod()
	{
		return mMethod.c_str();
	}
	
	const char * ConsoleItem::getText()
	{
		return mText.c_str();
	}
	
	const char * ConsoleItem::getName()
	{
		return mName.c_str();
	}
	
	int8_t ConsoleItem::getType()
	{
		return mType;
	}
	
	bool ConsoleItem::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) 
			|| ("" == mName) || ("" == mMethod) );
	}
	
	int16_t ConsoleItem::getKey()
	{
		return mIndex;
	}
	
	ConsoleItem::ConsoleItem()
		: mMethod ("")
		, mSwitch ("")
		, mText ("")
		, mType (0)
		, mIndex (0)
		, mName ("")
	{
	}
	
	ConsoleItem::~ConsoleItem()
	{
		mSwitch = "";
		mMethod = "";
		mText = "";
		mType = 0;
		mIndex = 0;
		mName = "";
	}
	
}
