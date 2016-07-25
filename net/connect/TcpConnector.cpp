#include "../../Engine.hpp"

namespace cc {
	
	void TcpConnector::runConnector(asio::ip::tcp::resolver::iterator& nIterator, ConnectInfo& nConnectInfo)
	{
		mDisconnectId = nConnectInfo.getDisconnectId();
		mTimeoutId = nConnectInfo.getTimeoutId();
		mConnectId = nConnectInfo.getConnectId();
		mAutoConnect = nConnectInfo.getAutoConnect();
		mExceptionId = nConnectInfo.getExceptionId();
		
		this->runClose();
		
		try {
			boost::asio::async_connect(mSocket, nIterator,
			boost::bind(&TcpConnector+::handleConnect, this, boost::asio::placeholders::error));
			
			mConnectTimer.expires_from_now(boost::posix_time::seconds(TcpConnector::connect_timeout));
			mConnectTimer.async_wait(boost::bind(&TcpConnector::handleConnectTimeout, 
				this, boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
		}
	}
	
	void TcpConnector::handleConnectTimeout(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runClose();
			
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_runIfSelect(mExceptionId, entity_, value_);
			return;
		}
		if (mConnectTimer.expires_at() <= asio::deadline_timer::traits_type::now()) {
			mConnectTimer.expires_at(boost::posix_time::pos_infin);
			
			this->runClose();
			
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_runIfSelect(mTimeoutId, entity_, value_);
		}
	}
	
	void TcpConnector::handleConnect(const boost::system::error_code& nError)
	{
		mConnectTimer.cancel();
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->runClose();
			
			SelectEngine& selectEngine_ = SelectEngine::instance();
			EntityPtr& entity_ = this->getEntity();
			ValuePtr value_(new Value());
			selectEngine_runIfSelect(mExceptionId, entity_, value_);
			
			return;
		}
		
		SelectEngine& selectEngine_ = SelectEngine::instance();
		EntityPtr& entity_ = this->getEntity();
		ValuePtr value_(new Value());
		selectEngine_runIfSelect(mExceptionId, entity_, value_);
	}
	
	TcpConnector::TcpConnector(asio::io_service& nIoService)
		: mConnectTimer (nIoService)
		, Session (nIoService)
		, mDisconnectId (0)
		, mConnectId (0)
		, mExceptionId (0)
		, mTimeoutId (0)
		, mAutoConnect (false)
	{
	}
	
	TcpConnector::~TcpConnector()
	{
		mDisconnectId = 0;
		mConnectId = 0;
		mTimeoutId = 0;
		mExceptionId = 0;
		mAutoConnect = false;
	}
	
}
