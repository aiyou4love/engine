#include "../Engine.hpp"

namespace cc {
	
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
	
	int16_t ConsoleItem::getKey()
	{
		return mIndex;
	}
	
	ConsoleItem::ConsoleItem()
		: mMethod ("")
		, mText ("")
		, mType (0)
		, mIndex (0)
		, mName ("")
	{
		LOGF;
	}
	
	ConsoleItem::~ConsoleItem()
	{
		LOGF;
		
		mMethod = "";
		mText = "";
		mType = 0;
		mIndex = 0;
		mName = "";
	}
	
}