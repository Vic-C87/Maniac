#pragma once

#include "Maniac/Input.h"

namespace Maniac
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int aKeycode) override;

		virtual bool IsMouseButtonPressedImpl(int aButton) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}