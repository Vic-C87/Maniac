#include "mnpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Input.h"

namespace Maniac
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::sInstance = nullptr;

	Application::Application()
	{
		MN_CORE_ASSERT(!sInstance, "Application already exists!");
		sInstance = this;

		myWindow = std::unique_ptr<Window>(Window::Create());
		myWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* aLayer)
	{
		myLayerStack.PushLayer(aLayer);
		aLayer->OnAttach();
	}

	void Application::PushOverlay(Layer* aLayer)
	{
		myLayerStack.PushOverlay(aLayer);
		aLayer->OnAttach();

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto itterator = myLayerStack.end(); itterator != myLayerStack.begin();)
		{
			(*--itterator)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}


	void Application::Run()
	{
		while (myRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : myLayerStack)
			{
				layer->OnUpdate();
			}
			myWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		myRunning = false;
		return true;
	}
}

