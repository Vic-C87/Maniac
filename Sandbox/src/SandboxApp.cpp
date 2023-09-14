#include "mnpch.h"
#include <Maniac.h>

class Sandbox : public Maniac::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Maniac::Application* Maniac::CreateApplication()
{
	return new Sandbox();
}