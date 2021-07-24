#include "vcepch.h"
#include "Application.h"

#include "VCE/Events/ApplicationEvent.h"
#include "Log.h"

namespace VCE {
	Application::Application() {
	}
	Application::~Application() {
	}
	void Application::Run() {
		WindowResizeEvent e(1200, 600);
		VCE_INFO(e);
		while (true);
	}
}