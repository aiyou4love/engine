#include "../../Engine.hpp"

namespace cc {
	
	void Entity::insertProperty(int32_t nPropertyId, PropertyPtr& nProperty)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it != mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return;
		}
		mPropertys[nPropertyId] = nProperty;
	}
	
	PropertyPtr& Entity::getProperty(int32_t nPropertyId)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it == mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return defaultPtr<Property>();
		}
		return it->second;
	}
	
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
	
	void Entity::pushValue(ValuePtr& nValue)
	{
		lock_guard<mutex> lock_(mMutex);
		mValues.push_back(nValue);
	}
	
	ValuePtr Entity::popValue()
	{
		lock_guard<mutex> lock_(mMutex);
		ValuePtr value_;
		if (mValues.size() > 0) {
			value_ = mValues.front();
			mValues.pop_front();
		}
		return value_;
	}
	
	Entity::Entity()
		: mIncrease (true)
		, mIfSelectId(0)
	{
		mSelectStates.clear();
		mPropertys.clear();
	}
	
	Entity::~Entity()
	{
		mSelectStates.clear();
		mPropertys.clear();
		
		mIfSelectId = 0;
		mIncrease = true;
	}
	
}
