#pragma once

#include "Maniac/Layer.h"

namespace Maniac
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;
		void OnEvent(Event& anEvent) override;
	private:

	};
}