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
	{
		mPropertys.clear();
		mValues.clear();
	}
	
	Entity::~Entity()
	{
		mPropertys.clear();
		mValues.clear();
	}
	
}
