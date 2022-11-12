#pragma once

#include "entt.hpp"

#include "Shotgun/Core/Timestep.h"

namespace Shotgun {
	
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep ts);

		// TODO: Remove this
		entt::registry& Reg() { return m_Registry; }

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}