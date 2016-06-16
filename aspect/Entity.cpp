#include "../../Include.hpp"

namespace cc {
	
	void Entity::startCondition()
	{
		mConditionId++;
	}
	
	void Entity::clearCondition()
	{
		
	}
	
	void Entity::endCondition()
	{
		
	}
	
	Entity::Entity()
		: mConditionId (0)
	{
		
	}
	
	Entity::~Entity()
	{
		mConditionId = 0;
	}
	
}
