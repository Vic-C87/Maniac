#include "mnpch.h"
#include "Application.h"

#include "Maniac/Events/ApplicationEvent.h"
#include "Maniac/Log.h"

namespace Maniac
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MN_TRACE(e);
		}

		while (true);
	}
}

