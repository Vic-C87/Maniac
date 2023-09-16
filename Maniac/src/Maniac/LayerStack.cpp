#include "mnpch.h"
#include "LayerStack.h"

namespace Maniac
{
	LayerStack::LayerStack()
	{
		myLayerInsert = myLayers.begin();
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
		myLayerInsert = myLayers.emplace(myLayerInsert, aLayer);
	}

	void LayerStack::PushOverlay(Layer* anOverlay)
	{
		myLayers.emplace_back(anOverlay);
	}

	void LayerStack::PopLayer(Layer* aLayer)
	{
		auto itterator = std::find(myLayers.begin(), myLayers.end(), aLayer);
		if (itterator != myLayers.end())
		{
			myLayers.erase(itterator);
			myLayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* anOverlay)
	{
		auto itterator = std::find(myLayers.begin(), myLayers.end(), anOverlay);
		if (itterator != myLayers.end())
		{
			myLayers.erase(itterator);
		}
	}
}