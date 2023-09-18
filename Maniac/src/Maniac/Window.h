#pragma once

#include "mnpch.h"

#include "Maniac/Core.h"
#include "Maniac/Events/Event.h"

namespace Maniac
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& aTitle = "Maniac Engine",
						unsigned int aWidth = 1280,
						unsigned int aHeight = 720)
			: Title(aTitle), Width(aWidth), Height(aHeight) {}
	};

	class MANIAC_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& aCallback) = 0;
		virtual void SetVSync(bool anEnabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& someProperties = WindowProps());

	};
}