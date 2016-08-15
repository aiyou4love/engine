#pragma once

namespace cc {
	
	class AcceptInfo : noncopyable
	{
	public:
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int16_t getDispatchId();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mAcceptInfoId, "acceptInfoId");
			
			nSerialize->runNumber(mDisconnectId, "disconnectId");
			nSerialize->runNumber(mExceptionId, "exceptionId");
			nSerialize->runNumber(mDispatchId, "dispatchId");
		}
		bool isDefault();
		int16_t getKey();
		
		AcceptInfo();
		~AcceptInfo();
		
	private:
		int16_t mAcceptInfoId;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int16_t mDispatchId;
	};
	typedef std::shared_ptr<AcceptInfo> AcceptInfoPtr;
	
}
