#pragma once

#include "Maniac/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Maniac
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* aWindowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* myWindowHandle;
	};
}
