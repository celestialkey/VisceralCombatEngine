#include "vcepch.h"
#include "RenderBuffers.h"

#include "RendererAPI.h"
#include "RenderBuffers.h"

#include "Platform/OpenGL/OpenGLBuffers.h"

namespace VCE {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    VCE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
		}

		VCE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    VCE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, size);
		}

		VCE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	
}