#pragma once

namespace std {
	
	class CloseEngine : noncopyable
	{
	public:
		template <class P>
		void runDoing(int32_t nId, P& nP, ValuePtr& nValue)
		{
			map<int32_t, ClosedPtr>::iterator it = mCloseds.find(nId);
			if ( it == mCloseds.end() ) {
				LOGERROR("[%s]%d", __METHOD__, nId);
				return;
			}
			ClosedPtr& closed_ = it->second;
			closed_->runDoing(nP, nValue);
		}
		
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runMapStreamPtrs<int32_t, ClosedPtr>(mCloseds, "closeds", "closed");
		}
		const char * streamName();
		
		void runPreinit();
		void runTable();
		
		CloseEngine();
		~CloseEngine();
		
	private:
		map<int32_t, ClosedPtr> mCloseds;
	};
	
}
