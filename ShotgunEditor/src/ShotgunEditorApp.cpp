#include <Shotgun.h>
#include <Shotgun/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Shotgun {

	class ShotgunEditor : public Application
	{
	public:
		ShotgunEditor(ApplicationCommandLineArgs args)
			: Application("Shotgun Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~ShotgunEditor()
		{
		}

	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new ShotgunEditor(args);
	}
		
}
