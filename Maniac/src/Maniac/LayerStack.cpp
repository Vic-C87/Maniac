#include "mnpch.h"
#include "LayerStack.h"

namespace Maniac
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : myLayers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* aLayer)
	{
		myLayers.emplace(myLayers.begin() + myLayerInsertIndex, aLayer);
		myLayerInsertIndex++;
		aLayer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer* anOverlay)
	{
		myLayers.emplace_back(anOverlay);
		anOverlay->OnAttach();
	}

	void LayerStack::PopLayer(Layer* aLayer)
	{
		auto itterator = std::find(myLayers.begin(), myLayers.end(), aLayer);
		if (itterator != myLayers.end())
		{
			myLayers.erase(itterator);
			myLayerInsertIndex--;
			aLayer->OnDetach();
		}
	}

	void LayerStack::PopOverlay(Layer* anOverlay)
	{
		auto itterator = std::find(myLayers.begin(), myLayers.end(), anOverlay);
		if (itterator != myLayers.end())
		{
			myLayers.erase(itterator);
			anOverlay->OnDetach();

		}
	}
}