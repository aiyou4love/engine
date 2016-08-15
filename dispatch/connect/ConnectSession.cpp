#include "../../Engine.hpp"

namespace cc {
	
	void ConnectSession::sendValue(int16_t nAppId, ValuePtr& nValue)
	{
		auto it = mSessions.find(nAppId);
		if ( it == mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		SessionPtr& session_ = mSessions[nAppId];
		session_->pushValue(nValue);
	}
	
	SessionPtr& ConnectSession::createSession(int16_t nAppId)
	{
		auto it = mSessions.find(nAppId);
		if ( it != mSessions.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
		}
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		SessionPtr session_(new Session(nAppId, ioHandle_));
		lock_guard<mutex> lock_(mMutex);
		mSessions[nAppId] = session_;
		return mSessions[nAppId];
	}
	
	void ConnectSession::runPreinit()
	{
	}
	
	void ConnectSession::runClear()
	{
		mSessions.clear();
	}
	
	ConnectSession& ConnectSession::instance()
	{
		return mConnectSession;
	}
	
	ConnectSession::ConnectSession()
	{
		mSessions.clear();
	}
	
	ConnectSession::~ConnectSession()
	{
		mSessions.clear();
	}
	
	ConnectSession ConnectSession::mConnectSession;
	
}
