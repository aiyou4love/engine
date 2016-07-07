#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		virtual EdoingState runCondition(EntityPtr& nEntity, ValuePtr& nValue) = 0;
		virtual void runReward(EntityPtr& nEntity, ValuePtr& nValue) = 0;
		
		void pushDoingState(int32_t nSelectId, EdoingState nDoingState);
		
		void startIfSelect(int32_t nIfSelectId);
		void startSelect(int32_t nSelectId);
		
		Entity();
		~Entity();
		
	private:
		map<int32_t, SelectStatePtr> mSelectStates;
		
		int32_t mIfSelectId;
		bool mIncrease;
	};
	typedef boost::shared_ptr<Entity> EntityPtr;
	
}
