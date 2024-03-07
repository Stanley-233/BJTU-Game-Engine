#pragma once

#include <glad/glad.h>

#include "runtime/function/render/render_texture.h"

#include <memory>
#include <cstdint>
#include <optional>
#include <string>

namespace BJTUGE {

class RenderShader {

public:
    RenderShader(const char* vertex_shader, const char* fragment_shader);
    ~RenderShader();

    uint32_t get() const { return m_shader_program; }
    void     use() const { glUseProgram(m_shader_program); }

    /**
     * @brief Set a uniform value in the shader.
     *        Be careful! Before calling this function, the shader MUSE be in USE!!
     */
    void setUniform(const char* name, int value) const { glUniform1i(glGetUniformLocation(m_shader_program, name), value); }
    void setUniform(const char* name, bool value) const { glUniform1i(glGetUniformLocation(m_shader_program, name), value); }
    void setUniform(const char* name, float value) const { glUniform1f(glGetUniformLocation(m_shader_program, name), value); }
    void setUniform(const char* name, float x, float y) const { glUniform2f(glGetUniformLocation(m_shader_program, name), x, y); }
    void setUniform(const char* name, uint32_t x, uint32_t y) const { glUniform2i(glGetUniformLocation(m_shader_program, name), x, y); }
    void setUniform(const char* name, float x, float y, float z) const { glUniform3f(glGetUniformLocation(m_shader_program, name), x, y, z); }
    void setUniform(const char* name, uint32_t value) const {
        glUniform1i(glGetUniformLocation(m_shader_program, name), static_cast<int>(value));
    }

    /**
     * @brief Set a texture in the shader.
     *
     * @param name The name of the texture in the shader.
     * @param texture_id The texture unit to bind the texture to.
     * @param texture The texture to bind.
     */
    void setTexture(const char* name, uint32_t texture_id, std::shared_ptr<RenderTexture> texture);

private:
    uint32_t m_shader_program;

    std::optional<std::string> getShaderCompileInfo(uint32_t shader);
    void                       assertShaderCompileSuccess(uint32_t shader);
    std::optional<std::string> getProgramCompileInfo(uint32_t program);
    void                       assertProgramCompileSuccess(uint32_t program);
};

} // namespace BJTUGE