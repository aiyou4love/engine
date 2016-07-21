#pragma once

namespace cc {
	
	class Entity;
	typedef std::shared_ptr<Entity> EntityPtr;
	class Property : noncopyable
	{
	public:
		void setEntity(EntityPtr& nEntity);
		EntityPtr& getEntity();
		
		Property();
		virtual ~Property();
		
	protected:
		EntityPtr * mEntity;
	};
	typedef shared_ptr<Property> PropertyPtr;
	
}
