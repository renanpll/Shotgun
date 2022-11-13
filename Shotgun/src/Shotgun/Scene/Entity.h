#pragma once

#include "Scene.h"

#include "entt.hpp"

namespace Shotgun {

	class Entity
	{

	public:
		Entity() = default;
		Entity(entt::entity entityHandle, Scene* scene)
			: m_EntityHandle(entityHandle), m_Scene(scene) {}

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			SG_CORE_ASSERT(!HasComponent<T>(), "Entity already has component");

			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			SG_CORE_ASSERT(HasComponent<T>(), "Entity doesn't have the component");

			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			SG_CORE_ASSERT(HasComponent<T>(), "Entity doesn't have the component");

			m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.any_of<T>(m_EntityHandle);
		}

		operator bool() const { return m_EntityHandle != entt::null; }

	private:
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr;

	};

}