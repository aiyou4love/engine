#include "../../Engine.hpp"

namespace cc {
	
	void SelectEngine::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		int32_t ifSelectId_ = nValue->getInt32(1);
		auto it = mIfSelects.find(ifSelectId_);
		if ( it == mIfSelects.end() ) {
			LOGE("[%s]%d", __METHOD__, ifSelectId_);
			return;
		}
		IfSelectPtr& ifSelect_ = it->second;
		int16_t appType0_ = ifSelect_->getAppType();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType1_ = workDirectory_.getAppType();
		
		if ( appType0_ == appType1_ ) {
			ifSelect_->runIfSelect(nEntity, nValue);
		} else if (appType0_ > appType1_) {
			ConnectEngine& connectEngine_ = ConnectEngine::instance();
			connectEngine_.sendValue(appType0_, nValue);
		} else {
			PropertyPtr& property_ = nEntity->getProperty(1);
			DispatchPtr dispatch_ = std::dynamic_pointer_cast<DispatchPtr>(property_);
			dispatch_->runValue(ifSelect_, nEntity, nValue);	
		}
	}
	
	void SelectEngine::runStart()
	{
		ApplicationEngine& applicationEngine_ = ApplicationEngine::instance();
		EntityPtr& entity_ = applicationEngine_->getEntity();
		
		auto it = mStartIds.begin();
		for ( ; it != mStartIds.end(); ++it ) {
			int32_t startId_ = (*it);
			ValuePtr value_(new Value());
			value_->pushInt32(startId_);
			this->runIfSelect(entity_, value_);
		}
	}
	
	void SelectEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&SelectEngine::runLuaApi, this));
		lifeCycle_.m_tLoadBegin.connect(bind(&SelectEngine::runLoad, this));
		lifeCycle_.m_tIniting.connect(bind(&SelectEngine::runInit, this));
	}
	
	void SelectEngine::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<SelectEngine>("SelectEngine");
		luaEngine_.runStatic<SelectEngine>(SelectEngine::instance, "instance");
		luaEngine_.runMethod<SelectEngine>(&SelectEngine::runIfSelect, "runIfSelect");
	}
	
	void SelectEngine::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runTable<SelectEngine *>(this, streamUrl(), streamName());
		tableEngine_.runTable<SelectEngine *>(this, startUrl(), startName());
	}
	
	void SelectEngine::runInit()
	{
		ContextPtr selectStart_(new SelectStart());
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(selectStart_);
	}
	
	const char * SelectEngine::streamName()
	{
		return "selectEngine";
	}
	
	const char * SelectEngine::streamUrl()
	{
		return "selectEngine.json";
	}
	
	const char * SelectEngine::startName()
	{
		return "selectStart";
	}
	
	const char * SelectEngine::startUrl()
	{
		return "selectStart.json";
	}
		
	SelectEngine& SelectEngine::instance()
	{
		return mSelectEngine;
	}
	
	SelectEngine::SelectEngine()
	{
		mIfSelects.clear();
		mStartIds.clear();
	}
	
	SelectEngine::~SelectEngine()
	{
		mIfSelects.clear();
		mStartIds.clear();
	}
	
	SelectEngine SelectEngine::mSelectEngine;
	
}
