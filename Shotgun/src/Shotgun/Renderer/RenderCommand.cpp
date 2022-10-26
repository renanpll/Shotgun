#include "sgpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Shotgun {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}