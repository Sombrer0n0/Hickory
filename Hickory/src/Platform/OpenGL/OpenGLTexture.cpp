﻿#include "hckpch.h"
#include "OpenGLTexture.h"

#include "stb_image.h"

#include <glad/glad.h>

namespace Hickory {

	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: m_Path(path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		HCK_CORE_ASSERT(data, "Failed to load image!");
		GLenum internalFmt = GL_RGB8, dataFmt=GL_RGB;
		if (channels == 4) {
			internalFmt = GL_RGBA8;
			dataFmt = GL_RGBA;
		}
		else if (channels == 3) {
			internalFmt = GL_RGB8;
			dataFmt = GL_RGB;
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		}
		else {
			HCK_CORE_ASSERT(false, "Unsupported channel count");
		}

		m_Width = width;
		m_Height = height;
		HCK_CORE_INFO("{0},{1}",width,height);

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalFmt, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, dataFmt, GL_UNSIGNED_BYTE, data);
		
		if (channels == 3)
			glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}
}