#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue);
		void runReward(DoingPtr& nDoing, ValuePtr& nValue);
		
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<string, UrlValuePtr>(mUrlValues, "urlValues", "urlValue");
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
		map<string, UrlValuePtr> mUrlValues;
		map<int32_t, IAspect *> mAspects;
		EntityPtr mAccount;
	};
#endif

}
