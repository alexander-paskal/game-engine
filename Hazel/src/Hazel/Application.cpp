#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"


namespace Hazel {
	 
	Application::Application()  // function corresponding to the one that was declared in the header
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 700);
		HZ_TRACE(e);

		while (true);
	}
}