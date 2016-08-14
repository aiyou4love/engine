#include "../../Engine.hpp"

namespace cc {
	
	void ConnectEngine::initConnect(int16_t nAppId, const char * nIp, const char * nPort, const char * nInfoId)
	{
		int32_t connectInfoId_ = stringCrc(nInfoId);
		auto it = mConnectInfos.find(connectInfoId_);
		if ( it == mConnectInfos.end() ) {
			LOGE("[%s]%s", __METHOD__, nInfoId);
			return;
		}
		ConnectInfoPtr& connectInfo_ = it->second;
		ConnectIpPtr connectIp_(new ConnectIp(nIp, nPort));
		
		this->initConnect(nEntity, connectIp_, connectInfo_);
	}
	
	void ConnectEngine::initConnect(int16_t nAppId, const char * nIpId, const char * nInfoId)
	{
		int32_t connectInfoId_ = stringCrc(nInfoId);
		auto it0 = mConnectInfos.find(connectInfoId_);
		if ( it0 == mConnectInfos.end() ) {
			LOGE("[%s]%s", __METHOD__, nInfoId);
			return;
		}
		ConnectInfoPtr& connectInfo_ = it0->second;
		
		int32_t connectIpId_ = stringCrc(nIpId);
		auto it1 = mConnectIps.find(connectIpId_);
		if ( it1 == mConnectIps.end() ) {
			LOGE("[%s]%s", __METHOD__, nIpId);
			return;
		}
		ConnectIpPtr& connectIp_ = it1->second;
		
		this->initConnect(nAppId, connectIp_, connectInfo_);
	}
	
	void ConnectEngine::initConnect(int16_t nAppId, ConnectIpPtr& nConnectIp, ConnectInfoPtr& nConnectInfo)
	{
		PropertyPtr& property_ = nEntity->getProperty(1);
		if (!property_) {
			PropertyPtr tempProperty_(new Dispatch());
			nEntity->insertProperty(1, tempProperty_);
			property_ = tempProperty_;
		}
		DispatchPtr dispatch_ = std::dynamic_pointer_cast<Dispatch>(property_);
		
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		ConnectorPtr connector_(new Connector(++mConnectId, ioHandle_));
		connector_->runConnect(nConnectIp, nConnectInfo);
		mConnectors[mConnectId] = connector_;
	}
	
	const char * ConnectEngine::streamName()
	{
		return "connectIp";
	}
	
	const char * ConnectEngine::streamUrl()
	{
		return "connectIp.json";
	}
	
	const char * ConnectEngine::infoName()
	{
		return "connectInfo";
	}
	
	const char * ConnectEngine::infoUrl()
	{
		return "connectInfo.json";
	}
	
	void ConnectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ConnectEngine::runLoad, this));
	}
	
	void ConnectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<ConnectEngine *>(this, streamUrl(), streamName());
		tableEngine_.runTable<ConnectEngine *>(this, infoUrl(), infoName());
	}
	
	ConnectEngine& ConnectEngine::instance()
	{
		return mConnectEngine;
	}
	
	ConnectEngine::ConnectEngine()
		: mConnectId (0)
	{
		mConnectInfos.clear();
		mConnectIps.clear();
		mConnectors.clear();
	}
	
	ConnectEngine::~ConnectEngine()
	{
		mConnectInfos.clear();
		mConnectIps.clear();
		mConnectors.clear();
		
		mConnectId = 0;
	}
	
	ConnectEngine ConnectEngine::mConnectEngine;
	
}
