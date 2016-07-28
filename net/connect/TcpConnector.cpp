#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnector::runConnector(asio::ip::tcp::resolver::iterator& nIterator, ConnectInfo& nConnectInfo)
	{
		mDisconnectId = nConnectInfo.getDisconnectId();
		mTimeoutId = nConnectInfo.getTimeoutId();
		mConnectId = nConnectInfo.getConnectId();
		mExceptionId = nConnectInfo.getExceptionId();
		
		try {
			boost::asio::async_connect(mSocket, nIterator,
			boost::bind(&TcpConnector::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runException();
		}
	}
	
	void TcpConnector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			
			this->runTimeout();
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runException();
			return;
		}
		mConnectTimer.cancel();
		
		this->runRead();
		this->runConnect();
	}
	
	void TcpConnector::runConnect()
	{
		if (mConnectId > 0) {
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_.runIfSelect(mConnectId, entity_, value_);
		}
	}
	
	void TcpConnector::runDisconnect()
	{
		Session::runDisconnect();
		
		if (mDisconnectId > 0) {
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_.runIfSelect(mDisconnectId, entity_, value_);
		}
	}
	
	void TcpConnector::runException()
	{
		Session::runException();
		
		if (mExceptionId > 0) {
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_.runIfSelect(mExceptionId, entity_, value_);
		}
	}
	
	void TcpConnector::runTimeout()
	{
		this->runClose();
		
		if (mTimeoutId > 0) {
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_.runIfSelect(mTimeoutId, entity_, value_);
		}
	}
	
	void TcpConnector::runClose()
	{
		Session::runClose();
		
		mConnectTimer.cancel();
	}
	
	TcpConnector::TcpConnector(asio::io_service& nIoService)
		: mConnectTimer (nIoService)
		, Session (nIoService)
		, mDisconnectId (0)
		, mConnectId (0)
		, mExceptionId (0)
		, mTimeoutId (0)
	{
	}
	
	TcpConnector::~TcpConnector()
	{
		mDisconnectId = 0;
		mConnectId = 0;
		mTimeoutId = 0;
		mExceptionId = 0;
	}
	
}
