#include "mnpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Maniac
{
	OpenGLContext::OpenGLContext(GLFWwindow* aWindowHandle)
		: myWindowHandle(aWindowHandle)
	{
		MN_CORE_ASSERT(aWindowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(myWindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MN_CORE_ASSERT(status, "Fail to initialize Glad!");
		
		MN_CORE_INFO("OpenGL info:");
		MN_CORE_INFO(" Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		MN_CORE_INFO(" Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		MN_CORE_INFO(" Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(myWindowHandle);
	}
}