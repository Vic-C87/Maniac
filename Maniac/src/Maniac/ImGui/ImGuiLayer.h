#pragma once

#include "Maniac/Layer.h"

namespace Maniac
{
	class MANIAC_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& anEvent);
	private:
		float myTime = 0.0f;
	};
}