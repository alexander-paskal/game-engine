#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(); // I guess this is just taking the CreateApplication function and putting it into the Hazel namespace

int main(int argc, char** argv)
{
	Hazel::Log::Init(); // obviously calls the Init method of the Log wrapper we made. I guess you use the colon when calling a method or accessing a variable, but not when
	// defining one?

	HZ_CORE_WARN("Initialized Log");
	int a = 5;
	HZ_INFO("Hello!, VAR = {0}", a);

	
	auto app = Hazel::CreateApplication(); // creates app for us by calling SandboxApp.cpp CreateApplication function
	app->Run();
	delete app; // deallocating space
}

#endif