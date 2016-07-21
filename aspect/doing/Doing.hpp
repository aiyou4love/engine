#pragma once

namespace cc {
	
	class Doing : noncopyable
	{
	public:
		template <class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumberCount(mAspectId, "aspectId", nCount);
			nSerialize->runNumberCount(mDoingId, "doingId", nCount);
			nSerialize->runNumberCount(mIndex, "index", nCount);
		}
		int32_t getAspectId();
		int32_t getDoingId();
		
		int8_t getKey();
		
		bool isDefault();
		
		Doing();
		~Doing();
		
	private:
		int32_t mAspectId;
		int32_t mDoingId;
		int8_t mIndex;
	};
	typedef std::shared_ptr<Doing> DoingPtr;
	
}
