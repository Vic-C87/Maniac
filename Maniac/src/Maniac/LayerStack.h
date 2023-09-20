#pragma once

#include "Maniac/Core.h"
#include "Layer.h"

#include <vector>

namespace Maniac
{
	class MANIAC_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* aLayer);
		void PushOverlay(Layer* anOverlay);
		void PopLayer(Layer* aLayer);
		void PopOverlay(Layer* anOverlay);

		std::vector<Layer*>::iterator begin() { return myLayers.begin(); }
		std::vector<Layer*>::iterator end() { return myLayers.end(); }
	private:
		std::vector<Layer*> myLayers;
		unsigned int myLayerInsertIndex = 0;
	};
}