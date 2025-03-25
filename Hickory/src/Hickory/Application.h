#pragma once
#include "Core.h"

#include "Window.h"

#include "Hickory/LayerStack.h"
#include "Hickory/Events/Event.h"
#include "Hickory/Events/ApplicationEvent.h"

namespace Hickory{
	class HCK_API Application
	{
	public:

		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
