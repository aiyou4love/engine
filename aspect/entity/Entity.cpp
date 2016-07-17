#include "../../Engine.hpp"

namespace cc {
	
	void Entity::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		LOGF;
		
		SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
		selectState_->pushDoingState(nDoingId, nDoingState);
		mIncrease = true;
	}
	
	void Entity::startIfSelect(int32_t nIfSelectId)
	{
		LOGF;
		
		if (mIncrease) {
			mIfSelectId++;
			SelectStatePtr selectState_(new SelectState(nIfSelectId));
			mSelectStates[mIfSelectId] = selectState_;
			mIncrease = false;
		} else {
			SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
			selectState_->setIfSelect(nIfSelectId);
		}
	}
	
	void Entity::startSelect(int32_t nSelectId)
	{
		LOGF;
		
		SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
		selectState_->setSelect(nSelectId);
	}
	
	Entity::Entity()
		: mIfSelectId(0)
		, mIncrease (true)
	{
		mSelectStates.clear();
	}
	
	Entity::~Entity()
	{
		mSelectStates.clear();
		
		mIfSelectId = 0;
		mIncrease = true;
	}
	
}
