#include "../../../Engine.hpp"

namespace cc {
	
	void Dispatch::runValue(int16_t nAppType, ValuePtr& nValue);
	{
		auto it = mSessions.find(nAppType);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppType);
			return;
		}
		SessionPt& session_ = it->second;
		session_->runSend(nValue);
	}
	
	Dispatch::Dispatch()
	{
		mSessions.clear();
	}
	
	Dispatch::~Dispatch()
	{
		mSessions.clear();
	}
	
}
