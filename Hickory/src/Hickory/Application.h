#pragma once
#include "Core.h"

#include "Window.h"

#include "Hickory/LayerStack.h"
#include "Hickory/Events/Event.h"
#include "Hickory/Events/ApplicationEvent.h"

#include "Hickory/ImGui/ImGuiLayer.h"

#include "Hickory/Renderer/Shader.h"
#include "Hickory/Renderer/Buffer.h"
#include "Hickory/Renderer/VertexArray.h"

#include "Hickory/Renderer/OrthographicCamera.h"

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
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}
