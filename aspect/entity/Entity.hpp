#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		virtual EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue) = 0;
		virtual void runReward(DoingPtr& nDoing, ValuePtr& nValue) = 0;
		
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
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
