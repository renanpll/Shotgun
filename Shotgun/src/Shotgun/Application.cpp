#include "Application.h"

#include "Shotgun/Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvents.h"

namespace Shotgun
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		KeyPressedEvent e(12, 10);
		if (e.IsInCategory(EventCategoryApplication)) {
			SG_CORE_TRACE(e);
		}
		else {
			SG_CORE_WARN(e);
		}

		while (true);
	}
}