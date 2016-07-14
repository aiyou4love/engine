#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccountEngine : public AccountEngine
	{
	public:
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
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
	};
#endif

}
