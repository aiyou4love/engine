#pragma once

namespace cc {
	
	class Dispatch : public Property
	{
	public:
		void runValue(int16_t nAppType, ValuePtr& nValue);
		
		Dispatch();
		~Dispatch();
		
	private:
		map<int16_t, SessionPt> mSessions;
	};
	typedef std::shared_ptr<Dispatch> DispatchPtr;
	
}
