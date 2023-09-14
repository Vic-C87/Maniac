#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Maniac/Events/ApplicationEvent.h"

#include "Window.h"

namespace Maniac
{
	class MANIAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> myWindow;
		bool myRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

