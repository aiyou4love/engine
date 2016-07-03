#pragma once

namespace cc {
	
	class Closed : noncopyable
	{
	public:
		void runDoing(EntityPtr& nEntity, ValuePtr& nValue, AspectEngine * nAspectEngine);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int8_t, DoingPtr>(mDoings, "doings", "doing", 10);
			
			nSerialize->runNumber(mId, "id");
		}
		int32_t getKey();
		
		Closed();
		~Closed();
		
	private:
		map<int8_t, DoingPtr> mDoings;
		
		int32_t mId;
	};
	typedef boost::shared_ptr<Closed> ClosedPtr;
	
}
