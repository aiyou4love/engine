#include "../Engine.hpp"

namespace cc {
	
	const char * ConsoleItem::getLuaMethod()
	{
		return mLuaMethod.c_str();
	}
	
	const char * ConsoleItem::getText()
	{
		return mText.c_str();
	}
	
	bool ConsoleItem::isGlob()
	{
		return mIsGlob;
	}
	
	int16_t ConsoleItem::getKey()
	{
		return mIndex;
	}
	
	ConsoleItem::ConsoleItem()
		: mLuaMethod ("")
		, mText ("")
		, mIndex (0)
		, mIsGlob (false)
	{
		LOGF;
	}
	
	ConsoleItem::~ConsoleItem()
	{
		LOGF;
		
		mLuaMethod = "";
		mText = "";
		mIndex = 0;
		mIsGlob = false;
	}
		
}
