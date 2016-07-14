#pragma once

namespace cc {
	
	class cAccountEngine : public AccountEngine
	{
	public:
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumber(mVersionNo, "versionNo");
				nSerialize.runNumber(mOperatorName, "operatorName");
				nSerialize.runNumber(mUpdateUrl, "updateUrl");
				nSerialize.runNumber(mTimeout, "timeout");
			} else if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.runStream(mServerList, "mServerList");
				nSerialize.runStream(mRoleList, "mRoleList");
				nSerialize.runStream(mAccount, "mAccount");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		
		const char * streamName();
		const char * streamUrl();
		
		const char * saveUrl();
		const char * saveName();
		
		cAccountEngine& instance();
		
		void runPreinit();
		void runLuaApi();
		void runLoad();
		
		cAccountEngine();
		~cAccountEngine();
		
	private:
		static cAccountEngine mAccountEngine;
		
		ServerList mServerList;
		RoleList mRoleList;
		cAccount mAccount;
		
		map<string, string> mAccountUrls;
	};
	
}
