#pragma once

#ifdef MN_PLATFORM_WINDOWS

extern Maniac::Application* Maniac::CreateApplication();

int main(int argc, char** argv)
{
	Maniac::Log::Init();
	MN_CORE_INFO("Log intialized!");



	auto app = Maniac::CreateApplication();

	app->Run();

	delete app;

	return 0;
}

#endif // MN_PLATFORM_WINDOWS
