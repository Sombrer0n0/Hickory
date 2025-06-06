#pragma once
#include "Core.h"

#include "Window.h"

#include "Hickory/LayerStack.h"
#include "Hickory/Events/Event.h"
#include "Hickory/Events/ApplicationEvent.h"

#include "Hickory/Core/Timestep.h"

#include "Hickory/ImGui/ImGuiLayer.h"

namespace Hickory{
	class Application
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
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
