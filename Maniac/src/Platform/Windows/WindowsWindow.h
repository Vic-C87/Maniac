#pragma once

#include "Maniac/Window.h"

#include "GLFW/glfw3.h"

namespace Maniac
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& someProperties);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return myData.Width; }
		inline unsigned int GetHeight() const override { return myData.Height; }

		inline void SetEventCallback(const EventCallbackFn& aCallback) override { myData.EventCallback = aCallback; }

		void SetVSync(bool anEnabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return myWindow; }
	private:
		virtual void Init(const WindowProps& someProperties);
		virtual void Shutdown();




		GLFWwindow* myWindow;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData myData;
	};
}