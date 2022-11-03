#include "sgpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Shotgun {

	/////////////////////////////////////////////////////////////////////////////
	//////////////////////////////// Shader /////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	Ref<Shader> Shader::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLShader>(path);
		}

		SG_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		SG_CORE_ASSERT(false, "Unknown Renderer API.");
		return nullptr;
	}

	/////////////////////////////////////////////////////////////////////////////
	//////////////////////////////// ShaderLibrary //////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		SG_CORE_ASSERT(!Exists(name), "Shader already exist");
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& path)
	{
		auto shader = Shader::Create(path);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& path)
	{
		auto shader = Shader::Create(path);
		Add(name, shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		SG_CORE_ASSERT(Exists(name), "Shader not found.");
		return m_Shaders[name];
	}
	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}