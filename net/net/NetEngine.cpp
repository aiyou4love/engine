#include "../../Engine.hpp"

namespace cc {
	
	void NetEngine::initNet(EntityPtr& nEntity, ConnectInfo& nConnectInfo)
	{		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		PropertyPtr& property_ = nEntity->getProperty(EpropertyType::mNetSession);
		if (!property_) {
			PropertyPtr tempProperty_(new TcpConnector(ioHandle_));
			nEntity->insertProperty(EpropertyType::mNetSession, tempProperty_);
			property_ = tempProperty_;
		}
		TcpConnectorPtr tcpConnector_ = std::dynamic_pointer_cast<TcpConnector>(property_);
		
		const char * serverIp_ = nConnectInfo.getServerIp();
		const char * serverPort_ = nConnectInfo.getServerPort();
		
		asio::ip::tcp::resolver resolver_(ioHandle_);
		asio::ip::tcp::resolver::query query_(serverIp_, serverPort_);
		asio::ip::tcp::resolver::iterator iterator_ = resolver_.resolve(query_);
		
		tcpConnector_->runConnector(iterator_, nConnectInfo);		
	}
	
	void NetEngine::sendNet(EntityPtr& nEntity, ValuePtr& nValue)
	{
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
