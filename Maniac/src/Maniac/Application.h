#pragma once

#include "Core.h"
#include "Window.h"

#include "Maniac/LayerStack.h"
#include "Maniac/Events/Event.h"
#include "Maniac/Events/ApplicationEvent.h"


namespace Maniac
{
	class MANIAC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* aLayer);
		void PushOverlay(Layer* aLayer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> myWindow;
		bool myRunning = true;
		LayerStack myLayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

