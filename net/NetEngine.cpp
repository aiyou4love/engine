#include "../../Engine.hpp"

namespace cc {
	
	void NetEngine::runSend(int16_t nAppType, EntityPtr& nEntity, ValuePtr& nValue)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType_ = workDirectory_.getAppType();
		
		if ( nAppType > appType_ ) {
			ConnectSession& connectSession_ = ConnectSession::instance();
			connectSession_.sendValue(nAppType, nValue);
		} else if ( nAppType < appType_ ) {
			PropertyPtr& property_ = nEntity->getProperty(1);
			SendPtr send_ = PTR_CAST<ISend>(property_);
			send_->sendValue(nValue);
		} else {
			LOGE("[%s]%d", __METHOD__, nAppType);
		}
	}
	
	NetEngine& NetEngine::instance()
	{
		return mNetEngine;
	}
	
	NetEngine::NetEngine()
	{
	}
	
	NetEngine::~NetEngine()
	{
	}
	
	NetEngine NetEngine::mNetEngine;
	
}
