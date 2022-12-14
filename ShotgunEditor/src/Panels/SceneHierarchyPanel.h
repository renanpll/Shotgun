#pragma once

#include "Shotgun/Core/Core.h"
#include "Shotgun/Core/Log.h"
#include "Shotgun/Scene/Scene.h"
#include "Shotgun/Scene/Entity.h"

namespace Shotgun {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

		void SetSelectedEntity(Entity entity) { m_SelectionContext = entity; }
		Entity GetSelectedEntity() const { return m_SelectionContext; }

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;

	};
}
