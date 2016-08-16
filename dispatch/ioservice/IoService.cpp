#include "../../Engine.hpp"

namespace cc {
	
	void IoService::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tInitBegin.connect(bind(&IoService::runInit, this));
		lifeCycle_.m_tStartBegin.connect(bind(&IoService::runStart, this));
		lifeCycle_.m_tRunning.connect(bind(&IoService::runRun, this));
		lifeCycle_.m_tStopBegin.connect(bind(&IoService::runStop, this));
	}
	
	void IoService::runInit()
	{
		for (int32_t i = 0; i < mIoServiceCount; ++i) {
			IoServicePtr ioService_(new asio::io_service());
			WorkPtr work_(new asio::io_service::work(*ioService_));
			mIoServices.push_back(ioService_);
			mWorks.push_back(work_);
		}
	}
	
	void IoService::runStart()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		mSignals.reset(new asio::signal_set(this->getIoService()));
		mSignals->add(SIGINT); mSignals->add(SIGTERM);
		mSignals->async_wait(boost::bind(&LifeCycle::stopBegin, &lifeCycle_));
	}
	
	void IoService::runRun()
	{
		vector<ThreadPtr> threads_;
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			ThreadPtr thread_(new std::thread(boost::bind(&asio::io_service::run, mIoServices[i])));
			threads_.push_back(thread_);
		}
	#ifdef __RUNING__
		for (size_t i = 0; i < threads_.size(); ++i) {
			threads_[i]->join();
		}
	#endif
	}
	
	void IoService::runStop()
	{
		for (size_t i = 0; i < mIoServices.size(); ++i) {
			mIoServices[i]->stop();
		}
	}
	
	asio::io_service& IoService::getIoService()
	{
		asio::io_service& ioService_ = (*(mIoServices[mNextIoService]));
		++mNextIoService;
		if (mNextIoService == mIoServices.size()) {
			mNextIoService = 0;
		}
		return ioService_;
	}
	
	void IoService::runClear()
	{
		//mIoServices.clear();
		//mWorks.clear();
		mNextIoService = 0;
		mIoServiceCount = 1;
	}
	
	IoService& IoService::instance()
	{
		return mIoService;
	}
	
	IoService::IoService()
	{
		this->runClear();
	}
	
	IoService::~IoService()
	{
		this->runClear();
	}
	
	IoService IoService::mIoService;
	
}
