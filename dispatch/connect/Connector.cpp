#include "../../Engine.hpp"

namespace cc {
	
	void Connector::runConnect(ConnectIpPtr& nConnectIp, ConnectInfoPtr& nConnectInfo)
	{
		mConnectErrorId = nConnectInfo->getConnectErrorId();
		mTimeoutId = nConnectInfo->getConnectId();
		mConnectId = nConnectInfo->getTimeoutId();
		
		ConnectSession& connectSession_ = ConnectSession::instance();
		mSession = &(connectSession_.createSession(nConnectId));
		
		int32_t disconnectId_ = nConnectInfo->getDisconnectId();
		int32_t exceptionId_ = nConnectInfo->getExceptionId();
		int16_t dispatchId_ = nConnectInfo->getDispatchId();
		
		(*mSession)->setDisconnect(disconnectId_);
		(*mSession)->setException(exceptionId_);
		(*mSession)->setDispatch(dispatchId_);
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		const char * serverPort_ = nConnectIp->getServerPort();
		const char * serverIp_ = nConnectIp->getServerIp();
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(serverIp_, serverPort_);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		try {
			boost::asio::async_connect((*mSession)->getSocket(), iterator_,
			boost::bind(&Connector::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->runConnectError();
		}
	}
	
	void Connector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runConnectError();
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			
			this->runTimeout();
		}
	}
	
	void Connector::handleConnect(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runConnectError();
			return;
		}
		mConnectTimer.cancel();
		(*mSession)->runRead();
		
		this->runConnect();
		
		ConnectEngine& connectEngine_ = ConnectEngine::instance();
		connectEngine_.removeConnector(mConnectId);
	}
	
	void Connector::runConnectError()
	{
		if (mConnectErrorId > 0) {
			ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
			EntityPtr& entity_ = applicationEngine_.getEntity();
			ValuePtr value_(new Value());
			value_->pushInt32(mConnectErrorId);
			entity_->pushValue(value_);	
		}
	}
	
	void Connector::runTimeout()
	{
		if (mTimeoutId > 0) {
			ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
			EntityPtr& entity_ = applicationEngine_.getEntity();
			ValuePtr value_(new Value());
			value_->pushInt32(mTimeoutId);
			entity_->pushValue(value_);	
		}
	}
	
	void Connector::runConnect()
	{
		if (mConnectId > 0) {
			ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
			EntityPtr& entity_ = applicationEngine_.getEntity();
			ValuePtr value_(new Value());
			value_->pushInt32(mConnectId);
			entity_->pushValue(value_);	
		}
	}
	
	Connector::Connector(int16_t nConnectId, asio::io_service& nHandle)
		: mConnectTimer (nHandle)
		, mConnectId (nConnectId)
		, mSession (nullptr)
	{
	}
	
	Connector::~Connector()
	{
		mConnectTimer.cancel();
		mSession = nullptr;
		mConnectId = 0;
	}
	
}

