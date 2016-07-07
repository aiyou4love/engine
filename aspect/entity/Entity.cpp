#include "../../Engine.hpp"

namespace cc {
	
	void Entity::pushDoingState(int8_t nDoingId, EdoingState nDoingState)
	{
		SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
		selectState_.pushDoingState(nDoingId, nDoingState);
		mIncrease = true;
	}
	
	void Entity::startIfSelect(int32_t nIfSelectId)
	{
		if (mIncrease) {
			mIfSelectId++;
			SelectStatePtr selectState_(new SelectState(nIfSelectId));
			mSelectStates[mIfSelectId] = selectState_;
			mIncrease = false;
		} else {
			SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
			selectState_.setIfSelectId(nIfSelectId);
		}
	}
	
	void Entity::startSelect(int32_t nSelectId)
	{
		SelectStatePtr& selectState_ = mSelectStates[mIfSelectId];
		selectState_.setSelectId(nSelectId);
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
