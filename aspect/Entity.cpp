#include "../../Include.hpp"

namespace cc {
	
	void Entity::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		CloseStatePtr& closeState_ = mCloseStates[mConditionId];
		closeState_.pushDoingState(nDoingId, nDoingState);
		mIncrease = true;
	}
	
	void Entity::startCondition(int32_t nCloseId)
	{
		if (mIncrease) {
			mConditionId++;
			CloseStatePtr closeState_(new CloseState(nCloseId));
			mCloseStates[mConditionId] = closeState_;
			mIncrease = false;
		} else {
			CloseStatePtr& closeState_ = mCloseStates[mConditionId];
			closeState_.setCloseId(nCloseId);
		}
	}
	
	Entity::Entity()
		: mConditionId (0)
		, mIncrease (true)
	{
		mCloseStates.clear();
	}
	
	Entity::~Entity()
	{
		mCloseStates.clear();
		
		mConditionId = 0;
		mIncrease = true;
	}
	
}
