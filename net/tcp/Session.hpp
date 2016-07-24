#pragma once

namespace cc {
	
	class Session : public std::enable_shared_from_this<Session>, public Property
	{
	public:
		
	public:
		enum { write_timeout = 150 };
		enum { read_timeout = 300 };
		
		Session(asio::io_service& nIoService);
		~Session();
		
	private:
	};
	typedef std::shared_ptr<Session> SessionPtr;
	typedef std::weak_ptr<Session> SessionWtr;
	
}
