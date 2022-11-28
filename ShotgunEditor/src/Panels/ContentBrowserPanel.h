#pragma once

#include <filesystem>

namespace Shotgun {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRenderer();

	private:
		std::filesystem::path m_CurrentDirectory;
	};
}
