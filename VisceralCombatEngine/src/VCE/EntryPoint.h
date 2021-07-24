#pragma once


#ifdef VCE_PLATFORM_WINDOWS
extern VCE::Application* VCE::CreateApplication();

int main(int argc, char** argv) {

	VisceralCombatEngine::Log::Init();
	auto app = VCE::CreateApplication();
	app->Run();
	delete app;
}
#else
#	error VCE only supports Windows!
#endif
