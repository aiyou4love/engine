#pragma once

namespace cc {
	
	class PlayerEngine : public AspectEngine
	{
	public:
		PlayerEngine& instance();
		
		PlayerEngine();
		~PlayerEngine();
		
	private:
		static PlayerEngine mPlayerEngine;
	};
	
}
