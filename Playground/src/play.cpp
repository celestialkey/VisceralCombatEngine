
#include <VCE.h>

#include <glm/vec3.hpp>

class ExampleLayer : public VCE::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}
	~ExampleLayer() {

	}
	void OnUpdate() override {
	}
	void OnAttach(){
	}
	void OnDetach(){

	}

	void OnEvent(VCE::Event& e) override {
		//VCE_TRACE("ExampleLayer::OnEvent -> {0}", e);
	}
};
class TestBed : public VCE::Application
{
public:
	TestBed() {
		PushLayer(new ExampleLayer());
	}
	~TestBed() {

	}

};


// Called by the engine (extern'd in it)
VCE::Application* VCE::CreateApplication() {
	return new TestBed();
}