#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		void registerAspect(int32_t nAspectId, IAspect * nAspect);
		
		int8_t isRegister(const char * nValue);
		int8_t registerAccount(const char * nName, const char * nPassword);
		int8_t loginAccount(const char * nName, const char * nPassword, int16_t nAccountType);
		int8_t roleCreate(const char * nRoleName, int16_t nRoleRace);
		void cancelAccount(int64_t nAccountId);
		void selectServer(int32_t nServerId, int32_t nRoleId);
		int8_t accountEnter();
		string startServers();
		string pageServers(int16_t nPageId, int16_t nPageCount);
		
		const char * getRoleName(int32_t nServerId, int32_t nRoleId);
		EntityPtr& getAccount();
		
	private:
		template <class T>
		void runClass(T nClass, string& nValue, const char * nName)
		{
			JsonReader jsonReader_;
			jsonReader_.stringValue(nValue.c_str());
			IoReader<JsonReader> ioReader_(jsonReader_);
			ioReader_.selectStream(nName);
			nClass->headSerialize(ioReader_, nName);
		}
		
		void runFormat(boost::format& nFormat);
		
		template <typename T0, typename ... T1>
		void runFormat(boost::format& nFormat, T0& nT0, T1& ... nT1)
		{
			nFormat % nT0;
			runFormat(nFormat, nT1 ...);
		}
		template <typename ... T>
		int8_t runHttp(string& nValue, int8_t nUrlId, T ... nArgs)
		{
			auto it = mUrlValues.find(nUrlId);
			if ( it == mUrlValues.end() ) {
				LOGE("[%s]%d", __METHOD__, nUrlId);
				return 3;
			}
			UrlValuePtr& urlValue_ = it->second;
			
			const char * urlNumber_ = urlValue_->getUrlValue();
			const char * urlBody_ = urlValue_->getUrlBody();
			int16_t timeout_ = urlValue_->getTimeout();
			int8_t urlType_ = urlValue_->getUrlType();
			
			boost::format format_(urlBody_);
			this->runFormat(format_, nArgs ...);
			
			string body_ = format_.str().c_str();
			body_ = stringDelete(body_, '\\');
			
			HttpCurl httpCurl_;
			CurlString curlString_;
			
			httpCurl_.runInit(urlNumber_);
			
			httpCurl_.runCurlValue(&curlString_);
			httpCurl_.runTimeout(timeout_);
			httpCurl_.runHttpHeader(urlType_);
			httpCurl_.runHttpPost(body_.c_str());
			
			if ( !httpCurl_.runPerform() ) {
				return 4;
			}
			httpCurl_.freeHttpHeader();
			nValue = curlString_.getValue();
			return 1;
		}
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int8_t, UrlValuePtr>(mUrlValues, "urlValues", "urlValue");
			} else if ( 0 == strcmp(saveName(), nName) ) {
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		
		const char * streamName();
		const char * streamUrl();
		
		const char * saveUrl();
		const char * saveName();
		
		static cAccountEngine& instance();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		map<int8_t, UrlValuePtr> mUrlValues;
		map<int32_t, IAspect *> mAspects;
		cRoleListPtr mRoleList;
		EntityPtr mAccount;
		
		ServerInfo mServerInfo;
        string mAgentPort;
        string mAgentIp;
	};
#endif

}
