#pragma once

#include <string>

namespace Shotgun {
	
	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<Shader> Create(const std::string& path);
		static Ref<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}