#pragma once

#include "Event.h"

namespace Maniac {

	class MANIAC_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: myMouseX(x), myMouseY(y) {}

		inline float GetX() const { return myMouseX; }
		inline float GetY() const { return myMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << myMouseX << ", " << myMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float myMouseX, myMouseY;
	};

	class MANIAC_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: myXOffset(xOffset), myYOffset(yOffset) {}

		inline float GetXOffset() const { return myXOffset; }
		inline float GetYOffset() const { return myYOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float myXOffset, myYOffset;
	};

	class MANIAC_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return myButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int aButton)
			: myButton(aButton) {}

		int myButton;
	};

	class MANIAC_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int aButton)
			: MouseButtonEvent(aButton) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << myButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MANIAC_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int aButton)
			: MouseButtonEvent(aButton) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << myButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}