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
		
		this->initConnect(nAppId, connectIp_, connectInfo_);
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
		IoService& ioService_ = IoService::instance();
		asio::io_service& ioHandle_ = ioService_.getIoService();
		
		ConnectorPtr connector_(new Connector(++nAppId, ioHandle_));
		connector_->runConnect(nConnectIp, nConnectInfo);
		mConnectors[nAppId] = connector_;
	}
	
	void ConnectEngine::removeConnector(int16_t nAppId)
	{
		auto it = mConnectors.find(nAppId);
		if ( it == mConnectors.end() ) {
			LOGE("[%s]%d", __METHOD__, nAppId);
			return;
		}
		mConnectors.erase(it);
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
	}
	
	ConnectEngine ConnectEngine::mConnectEngine;
	
}
