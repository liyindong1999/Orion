#pragma once

#include "Orion/Core.h"
#include "Orion/Layer.h"

using namespace std;

namespace Orion
{
	class ORION_API LayerStack
	{
	private:
		vector<Layer*> m_Layers;
		vector<Layer*>::iterator m_LayerInsert;

	public:
		LayerStack();
		~LayerStack();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		vector<Layer*>::iterator end() { return m_Layers.end(); }

	};
	
}
