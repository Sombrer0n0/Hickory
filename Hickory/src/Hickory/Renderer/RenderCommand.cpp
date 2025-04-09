#include "hckpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Hickory {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}