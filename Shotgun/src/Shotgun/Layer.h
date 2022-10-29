#pragma once

#include "Shotgun/Core.h"
#include "Shotgun/Core/Timestep.h"
#include "Shotgun/Events/Event.h"

namespace Shotgun {

	class SHOTGUN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
