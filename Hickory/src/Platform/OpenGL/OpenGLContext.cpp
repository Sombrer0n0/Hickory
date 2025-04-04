#include "hckpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Hickory {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HCK_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HCK_CORE_ASSERT(status, "Failed to initialize Glad!");

		HCK_CORE_INFO("OpenGL Info:");
		HCK_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		HCK_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		HCK_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}