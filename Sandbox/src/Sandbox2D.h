#pragma once

#include "Hickory.h"

class Sandbox2D : public Hickory::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hickory::Timestep& ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hickory::Event& e) override;
private:
	Hickory::OrthographicCameraController m_CameraController;

	// Temp
	Hickory::Ref<Hickory::VertexArray> m_SquareVA;
	Hickory::Ref<Hickory::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};