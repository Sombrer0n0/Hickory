#include <Hickory.h>

class ExampleLayer : public Hickory::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Hickory::Input::IsKeyPressed(HCK_KEY_TAB))
			HCK_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Hickory::Event& event) override
	{
		if (event.GetEventType() == Hickory::EventType::KeyPressed)
		{
			Hickory::KeyPressedEvent& e = (Hickory::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HCK_KEY_TAB) 
				HCK_TRACE("Tab key is pressed (event)!");
			HCK_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox :public Hickory::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hickory::ImGuiLayer());
	}
	~Sandbox() {
		 
	}
	
};

Hickory::Application* Hickory::CreateApplication() {

	return new Sandbox();	
}