#pragma once

namespace cc {
	
	class IfSelect : noncopyable
	{
	public:
		void runIfSelect(EntityPtr& nEntity, ValuePtr& nValue);
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runMapStreamPtrsCount<int8_t, SelectorPtr>(mSelectors, "selectors", "selector", 10);
			
			nSerialize->runNumber(mIfSelectId, "ifSelectorId");
		}
		bool isDefault();
		int32_t getKey();
		
		IfSelect();
		~IfSelect();
		
	private:
		map<int8_t, SelectorPtr> mSelectors;
		
		int32_t mIfSelectId;
	};
	typedef SPTR<IfSelect> IfSelectPtr;
	
}
