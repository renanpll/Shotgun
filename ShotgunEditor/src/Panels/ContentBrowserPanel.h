#pragma once

#include <filesystem>
#include "Shotgun/Renderer/Texture.h"

namespace Shotgun {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRenderer();

	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
		Ref<Texture2D> m_BackIcon;
	};
}
