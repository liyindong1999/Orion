#pragma once

#include "Orion/Core.h"
#include "Orion/Events/Event.h"

using namespace std;

namespace Orion
{
	class ORION_API Layer
	{
	protected:
		string m_DebugName;

	public:
		Layer(const string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const string& GetName() { return m_DebugName; }
	};
}

