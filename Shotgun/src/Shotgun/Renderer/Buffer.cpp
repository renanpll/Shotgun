#include "sgpch.h"
#include "Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Renderer.h"

namespace Shotgun {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		SG_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::OpenGL:
				return new OpenGLIndexBuffer(indices, size);
				int i = 0;
			}

		SG_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}

}