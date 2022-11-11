#include "sgpch.h"

#include "FrameBuffer.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Shotgun {

	Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLFrameBuffer>(spec);
		}

		SG_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}
}