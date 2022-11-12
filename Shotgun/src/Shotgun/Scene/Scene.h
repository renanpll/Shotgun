#pragma once

#include "entt.hpp"

#include "Shotgun/Core/Timestep.h"

namespace Shotgun {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		void OnUpdate(Timestep ts);

		// TODO: Remove this
		entt::registry& Reg() { return m_Registry; }

	private:
		entt::registry m_Registry;
	};
}