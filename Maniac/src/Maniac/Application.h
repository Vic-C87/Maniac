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

		inline Window& GetWindow() { return *myWindow; }
		inline static Application& Get() { return *sInstance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> myWindow;
		bool myRunning = true;
		LayerStack myLayerStack;
	private:
		static Application* sInstance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

