#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		void startCondition(int32_t nCloseId);
		
		Entity();
		~Entity();
		
	private:
		map<int32_t, CloseStatePtr> mCloseStates;
		
		int32_t mConditionId;
		bool mIncrease;
	};
	typedef boost::shared_ptr<Entity> EntityPtr;
	
}
