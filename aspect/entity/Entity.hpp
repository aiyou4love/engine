#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void insertProperty(int32_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr& getProperty(int32_t nPropertyId);
		
		virtual EdoingState runCondition(DoingPtr& nDoing, ValuePtr& nValue) = 0;
		virtual void runReward(DoingPtr& nDoing, ValuePtr& nValue) = 0;
		
		void pushDoingState(int8_t nDoingId, EdoingState nDoingState);
		
		void startIfSelect(int32_t nIfSelectId);
		void startSelect(int32_t nSelectId);
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int32_t, SelectStatePtr> mSelectStates;
		
		map<int32_t, PropertyPtr> mPropertys;
		
		int32_t mIfSelectId;
		bool mIncrease;
	};
	
}
