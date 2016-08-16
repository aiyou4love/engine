#include "../../Engine.hpp"

namespace cc {
	
	void AcceptEngine::handleAccept(const boost::system::error_code& nError)
	{
		if (nError) {
			LOGE("[%s]%s", __METHOD__, nError.message());
			this->stopEnd();
			return;
		}
		(*mSession)->runRead();
		startAccept();
	}
	
	void AcceptEngine::initAccept(const char * nIp, const char * nPort)
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		mAcceptor.reset(new asio::ip::tcp::acceptor(ioHandle_));
		
		asio::ip::tcp::resolver resolver_(mAcceptor->get_io_service());
		asio::ip::tcp::resolver::query query_(nIp, nPort);
		asio::ip::tcp::endpoint endpoint_ = *resolver_.resolve(query_);
		mAcceptor->open(endpoint_.protocol());
		mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
		mAcceptor->bind(endpoint_);
		mAcceptor->listen();
		startAccept();
	}
	
	void AcceptEngine::initAccept(int16_t nIpId)
	{
		auto it = mAcceptIps.find(int16_t);
		if ( it == mAcceptIps.end() ) {
			LOGE("[%s]%s", __METHOD__, nIpId);
			return;
		}
		AcceptIpPtr& acceptIp_ = it->second;
		
		const char * port_ = acceptIp_->getServerPort();
		const char * ip_ = acceptIp_->getServerIp();
		
		this->initAccept(ip_, port_);
	}
	
	void AcceptEngine::startAccept()
	{
		try {
			SessionMgr& sessionMgr_ = SessionMgr::instance();
			mNewSession = &(sessionService_.createSession());
			
			mAcceptor->async_accept((*mNewSession)->getSocket(),
				boost::bind(&AcceptEngine::handleAccept, this, 
				boost::asio::placeholders::error));
		} catch (boost::system::system_error& e) {
			LOGE("[%s]%s", __METHOD__, e.what());
			this->stopEnd();
		}
	}
	
	const char * AcceptEngine::streamName()
	{
		return "acceptInfo";
	}
	
	const char * AcceptEngine::streamUrl()
	{
		return "acceptInfo.json";
	}
	
	void AcceptEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&AcceptEngine::runLoad, this));
		lifeCycle_.m_tStopEnd.connect(bind(&AcceptEngine::stopEnd, this));
	}
	
	void AcceptEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<AcceptEngine *>(this, streamUrl(), streamName());
	}
	
	void AcceptEngine::stopEnd()
	{
		if (!mAcceptor) {
			return;
		}
 		mAcceptor->close();
	}
	
	AcceptEngine::AcceptEngine()
		: mNewSession(nullptr)
	{
	}
	
	AcceptEngine::~AcceptEngine()
	{
		mNewSession = nullptr;
	}
	
	static AcceptEngine AcceptEngine::mAcceptEngine;
	
}
