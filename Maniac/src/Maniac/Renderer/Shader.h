#pragma once

#include <string>

namespace Maniac
{
	class Shader
	{
	public:
		Shader(const std::string& aVertexSource, const std::string aFragmentSource);
		~Shader();

		void Bind() const;
		void Unbind() const;

	private:
		uint32_t myRendererID;
	};


}