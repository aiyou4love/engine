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
	
	void AcceptEngine::startAccept(const char * nIp, char * nPort)
	{
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		mAcceptor.reset(new asio::ip::tcp::acceptor(ioHandle_));
		
		asio::ip::tcp::resolver resolver_(mAcceptor->get_io_service());
		asio::ip::tcp::resolver::query query_(mAddress, mPort);
		asio::ip::tcp::endpoint endpoint_ = *resolver_.resolve(query_);
		mAcceptor->open(endpoint_.protocol());
		mAcceptor->set_option(asio::ip::tcp::acceptor::reuse_address(true));
		mAcceptor->bind(endpoint_);
		mAcceptor->listen();
		startAccept();
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
	
	void AcceptEngine::stopEnd()
	{
		if (!mAcceptor) {
			return;
		}
 		mAcceptor->close();
	}
	
	void AcceptEngine::runPreinit()
	{
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
