#pragma once

#include "Core.h"
#include "Window.h"

#include "Maniac/LayerStack.h"
#include "Maniac/Events/Event.h"
#include "Maniac/Events/ApplicationEvent.h"

#include "Maniac/ImGui/ImGuiLayer.h"

#include "Maniac/Renderer/Shader.h"

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
		ImGuiLayer* myImGuiLayer;
		bool myRunning = true;
		LayerStack myLayerStack;

		unsigned int myVertexArray;
		unsigned int myVertexBuffer;
		unsigned int myIndexBuffer;

		std::unique_ptr<Shader> myShader;
	private:
		static Application* sInstance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

