#pragma once

namespace std {
	
	class Doing : noncopyable
	{
	public:
		template <class __t>
		void serialize(__t * nSerialize, int8_t nCount)
		{
			nSerialize->runNumberCount(mAspectId, "aspectId", nCount);
			nSerialize->runNumberCount(mDoingId, "doingId", nCount);
			nSerialize->runNumberCount(mId, "id", nCount);
		}
		int32_t getAspectId();
		int32_t getDoingId();
		int32_t getKey();
		bool isDefault();
		
		Doing();
		~Doing();
		
	private:
		int32_t mAspectId;
		int32_t mDoingId;
		int32_t mId;
	};
	typedef shared_ptr<Doing> DoingPtr;
	
}
