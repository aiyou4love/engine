#pragma once

namespace cc {
	
	class IoService : boost::noncopyable
	{
	public:
		asio::io_service& getIoService();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mIoServiceCount, "ioServiceCount");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runStop();
		void runRun();
		
		static IoService& instance();
		
		IoService();
		~IoService();
		
	private:
		void runClear();
		
	private:
		typedef std::shared_ptr<asio::io_service> IoServicePtr;
		typedef std::shared_ptr<asio::io_service::work> WorkPtr;
		std::shared_ptr<asio::signal_set> mSignals;
		vector<IoServicePtr> mIoServices;
		vector<WorkPtr> mWorks;
		size_t mNextIoService;
		int16_t mIoServiceCount;
		
		static IoService mIoService;
	};
	
}
