
#include <VCE.h>

class TestBed : public VCE::Application
{
public:
	TestBed() {
	}
	~TestBed() {

	}

};


// Called by the engine (extern'd in it)
VCE::Application* VCE::CreateApplication() {
	return new TestBed();
}