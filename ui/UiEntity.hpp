#pragma once

namespace cc {
	
	class UiEntity : noncopyable
	{
	public:
		void runShow();
		void runRefresh(const char * nEvent);
		void runClose();
		
		UiEntity(const char * nName);
		~UiEntity();
		
	private:		
		string mName;
	};
	typedef boost::shared_ptr<UiEntity> UiEntityPtr;
	
}
