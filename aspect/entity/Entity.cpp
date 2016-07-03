#include "../../Include.hpp"

namespace cc {
	
	void Entity::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		CloseStatePtr& closeState_ = mCloseStates[mConditionId];
		closeState_.pushDoingState(nDoingId, nDoingState);
		mIncrease = true;
	}
	
	void Entity::startIfSelect(int32_t nSelectId)
	{
		if (mIncrease) {
			mSelectId++;
			SelectStatePtr selectState_(new SelectState(mSelectId));
			mSelectStates[mSelectId] = selectState_;
			mIncrease = false;
		} else {
			SelectStatePtr& selectState_ = mSelectStates[mSelectId];
			selectState_.setSelectId(nSelectId);
		}
	}
	
	Entity::Entity()
		: mSelectId (0)
		, mIncrease (true)
	{
		mSelectStates.clear();
	}
	
	Entity::~Entity()
	{
		mSelectStates.clear();
		
		mSelectId = 0;
		mIncrease = true;
	}
	
}
