#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int32_t getConnectId();
		int32_t getTimeoutId();
		int16_t getDispatchId();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mConnectInfoId, "connectInfoId");
			nSerialize->runNumber(mDisconnectId, "disconnectId");
			nSerialize->runNumber(mExceptionId, "exceptionId");
			nSerialize->runNumber(mConnectId, "connectId");
			nSerialize->runNumber(mTimeoutId, "timeoutId");
			nSerialize->runNumber(mDispatchId, "dispatchId");
		}
		bool isDefault();
		int16_t getKey();
		
		ConnectInfo();
		~ConnectInfo();
		
	private:
		int16_t mConnectInfoId;
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int32_t mConnectId;
		int32_t mTimeoutId;
		int16_t mDispatchId;
	};
	typedef std::shared_ptr<ConnectInfo> ConnectInfoPtr;
	
}
