#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void startCondition();
		void clearCondition();
		void endCondition();
		
		Entity();
		~Entity();
		
	private:
		map<int32_t, CloseStatePtr> mCloseStates;
		
		int32_t mConditionId;
	};
	typedef shared_ptr<Entity> EntityPtr;
	
}
