#pragma once

#include "Maniac/Layer.h"

#include "Maniac/Events/ApplicationEvent.h"
#include "Maniac/Events/KeyEvent.h"
#include "Maniac/Events/MouseEvent.h"

namespace Maniac
{
	class MANIAC_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float myTime = 0.0f;
	};
}