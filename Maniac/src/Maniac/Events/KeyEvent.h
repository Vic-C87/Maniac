#pragma once

#include "Event.h"


namespace Maniac {

	class MANIAC_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return myKeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int aKeycode)
			: myKeyCode(aKeycode) {}

		int myKeyCode;
	};

	class MANIAC_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int aKeycode, int aRepeatCount)
			: KeyEvent(aKeycode), myRepeatCount(aRepeatCount) {}

		inline int GetRepeatCount() const { return myRepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << myKeyCode << " (" << myRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int myRepeatCount;
	};

	class MANIAC_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int aKeycode)
			: KeyEvent(aKeycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << myKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class MANIAC_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int aKeyCode)
			: KeyEvent(aKeyCode)	{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << myKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}