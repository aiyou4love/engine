#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void pushDoingState(int32_t nSelectId, EdoingState nDoingState);
		
		void startIfSelect(int32_t nIfSelectId);
		
		Entity();
		~Entity();
		
	private:
		map<int32_t, SelectStatePtr> mSelectStates;
		
		int32_t mSelectId;
		bool mIncrease;
	};
	typedef boost::shared_ptr<Entity> EntityPtr;
	
}
