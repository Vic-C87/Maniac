#pragma once

#include "Core.h"

namespace Maniac
{
	class MANIAC_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

