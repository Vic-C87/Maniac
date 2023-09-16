#pragma once

#include "Maniac/Core.h"
#include "Maniac/Events/Event.h"

namespace Maniac
{
	class MANIAC_API Layer
	{
	public:
		Layer(const std::string& aDebugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return myDebugName; }
	protected:
		std::string myDebugName;

	};
}