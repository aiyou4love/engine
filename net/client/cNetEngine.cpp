#include "../../Engine.hpp"

namespace cc {
	
	void cNetEngine::initNet(EntityPtr& nEntity, const char * nIp, const char * nPort, int32_t nConnectId, int32_t nDisconnectId)
	{
		LOGF;
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		PropertyPtr property_ = nEntity->getProperty(EpropertyType::mNetSession);
		if (!property_) {
			property_.reset(new TcpConnector(ioHandle_));
			nEntity->insertProperty(EpropertyType::mNetSession, property_);
		}
		TcpConnectorPtr tcpConnector_ = std::dynamic_pointer_cast<TcpConnector>(property_);
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(nIp, nPort);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		tcpConnector_->runConnector(iterator, nConnectId, nDisconnectId);		
	}
	
	void cNetEngine::sendNet(EntityPtr& nEntity, ValuePtr& nValue)
	{
		LOGF;
	}
	
	cNetEngine& cNetEngine::instance()
	{
		LOGF;
		
		return mNetEngine;
	}
	
	cNetEngine::cNetEngine()
	{
	}
	
	cNetEngine::~cNetEngine()
	{
	}
	
	cNetEngine cNetEngine::mNetEngine;
	
}
