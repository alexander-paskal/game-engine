#pragma once


#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(); // I guess this is just taking the CreateApplication function and putting it into the Hazel namespace

int main(int argc, char** argv)
{
	printf("Hazel Engine");
	auto app = Hazel::CreateApplication(); // creates app for us by calling SandboxApp.cpp CreateApplication function
	app->Run();
	delete app; // deallocating space
}

#endif