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
		lock_guard<mutex> lock_(mMutex);
		auto it = mSessions.find(nAppId);
		if ( it != mSessions.end() ) {
			return mSessions[nAppId];
		}
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		SessionPtr session_(new Session(0, ioHandle_));
		session_->setAccept(false);
		mSessions[nAppId] = session_;
		return mSessions[nAppId];
	}
	
	void ConnectSession::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunClear.connect(bind(&ConnectSession::runClear, this));
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
