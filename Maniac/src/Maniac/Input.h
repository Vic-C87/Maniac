#pragma once

#include "Maniac/Core.h"

namespace Maniac
{
	class MANIAC_API Input
	{
	public:
		inline static bool IsKeyPressed(int aKeyCode) { return sInstance->IsKeyPressedImpl(aKeyCode); }
		inline static bool IsMouseButtonPressed(int aButton) { return sInstance->IsMouseButtonPressedImpl(aButton); }
		inline static std::pair<float, float> GetMousePosition() { return sInstance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return sInstance->GetMouseXImpl(); }
		inline static float GetMouseY() { return sInstance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int aKeycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int aButton) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* sInstance;
	};
}