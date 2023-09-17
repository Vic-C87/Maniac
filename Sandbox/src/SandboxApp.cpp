#include <Maniac.h>

class ExampleLayer : public Maniac::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		MN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Maniac::Event& anEvent) override
	{
		MN_TRACE("{0}", anEvent);
	}
};


class Sandbox : public Maniac::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Maniac::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Maniac::Application* Maniac::CreateApplication()
{
	return new Sandbox();
}