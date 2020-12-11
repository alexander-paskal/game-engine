#pragma once

#include "Core.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();  // The constructor I guess? I suppose in the header you declare the namespace and the methods you want to create
		virtual ~Application(); // The destructor for the application class

		void Run();
	};
	
	// to be defined in client	
	Application* CreateApplication();

}