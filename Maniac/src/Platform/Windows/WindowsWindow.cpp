#include "mnpch.h"
#include "WindowsWindow.h"

#include "Maniac/Events/ApplicationEvent.h"
#include "Maniac/Events/MouseEvent.h"
#include "Maniac/Events/KeyEvent.h"

#include "glad/glad.h"

namespace Maniac
{
	static bool sGLFWInitialized = false;

	static void GLFWErrorCallback(int anError, const char* aDescription)
	{
		MN_CORE_ERROR("GLFW Error ({0}): {1}", anError, aDescription);
	}

	Window* Window::Create(const WindowProps& someProperties)
	{
		return new WindowsWindow(someProperties);
	}

	WindowsWindow::WindowsWindow(const WindowProps& someProperties)
	{
		Init(someProperties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& someProperties)
	{
		myData.Title = someProperties.Title;
		myData.Width = someProperties.Width;
		myData.Height = someProperties.Height;

		MN_CORE_INFO("Creating window {0} ({1}, {2})", someProperties.Title, someProperties.Width, someProperties.Height);

		if (!sGLFWInitialized)
		{
			int success = glfwInit();
			MN_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			sGLFWInitialized = true;
		}

		myWindow = glfwCreateWindow((int)someProperties.Width, (int)someProperties.Height, myData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(myWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MN_CORE_ASSERT(status, "Failed to initialize Glad!");
		glfwSetWindowUserPointer(myWindow, &myData);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(myWindow, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(myWindow, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(myWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetCharCallback(myWindow, [](GLFWwindow* aWindow, unsigned int aKeyCode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(aWindow);

				KeyTypedEvent event(aKeyCode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(myWindow, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(myWindow, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(myWindow, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(myWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(myWindow);
	}

	void WindowsWindow::SetVSync(bool anEnabled)
	{
		if (anEnabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		myData.VSync = anEnabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return myData.VSync;
	}
}
