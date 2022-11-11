#include <Shotgun.h>
#include <Shotgun/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Shotgun {

	class ShotgunEditor : public Application
	{
	public:
		ShotgunEditor()
		{
			PushLayer(new EditorLayer());
		}

		~ShotgunEditor()
		{
		}

	};

	Application* CreateApplication()
	{
		return new ShotgunEditor();
	}

}