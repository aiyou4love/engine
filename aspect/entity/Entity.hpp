#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void insertProperty(int32_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr& getProperty(int32_t nPropertyId);
		
		virtual bool runCondition(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue) = 0;
		virtual void runReward(EntityPtr& nEntity, DoingPtr& nDoing, ValuePtr& nValue) = 0;
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int32_t, PropertyPtr> mPropertys;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
