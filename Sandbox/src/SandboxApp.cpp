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
		if (Maniac::Input::IsKeyPressed(MN_KEY_TAB))
		{
			MN_TRACE("Tab key is pressed (poll)!");
		}
	}

	void OnEvent(Maniac::Event& anEvent) override
	{
		if (anEvent.GetEventType() == Maniac::EEventType::KeyPressed)
		{
			Maniac::KeyPressedEvent& e = (Maniac::KeyPressedEvent&)anEvent;
			if (e.GetKeyCode() == MN_KEY_TAB)
			{
				MN_TRACE("Tab key is pressed (event)!");
			}
			MN_TRACE("{0}", (char)e.GetKeyCode());
		}
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