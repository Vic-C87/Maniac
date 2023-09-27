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

		myImGuiLayer = new ImGuiLayer();
		PushOverlay(myImGuiLayer);

		glGenVertexArrays(1, &myVertexArray);
		glBindVertexArray(myVertexArray);

		glGenBuffers(1, &myVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, myVertexBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &myIndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndexBuffer);

		unsigned int indicies[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* aLayer)
	{
		myLayerStack.PushLayer(aLayer);		
	}

	void Application::PushOverlay(Layer* aLayer)
	{
		myLayerStack.PushOverlay(aLayer);
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
			glClearColor(.1f, .1f, .1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindVertexArray(myVertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : myLayerStack)
			{
				layer->OnUpdate();
			}

			myImGuiLayer->Begin();
			for (Layer* layer : myLayerStack)
			{
				layer->OnImGuiRender();
			}
			myImGuiLayer->End();

			myWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		myRunning = false;
		return true;
	}
}

