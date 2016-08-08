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
	
	Entity::Entity()
	{
		mPropertys.clear();
	}
	
	Entity::~Entity()
	{
		mPropertys.clear();
	}
	
}
