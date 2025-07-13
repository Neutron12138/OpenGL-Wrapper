#pragma once

#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture);

    /// @brief 纹理对象
    class Texture : public Resource
    {
    public:
        static inline bool is_texture(GLuint id) { return glIsTexture(id); }

    private:
        /// @brief 纹理类型
        GLenum m_type = 0;

    public:
        inline Texture() = default;
        inline Texture(GLenum type) : m_type(type) { create(type); }
        inline Texture(Texture &&from) : Resource(std::move(from)), m_type(std::exchange(from.m_type, 0)) {}
        inline ~Texture() override { destroy(); }
        BASE_DELETE_COPY_FUNCTION(Texture);

    public:
        Texture &operator=(Texture &&from);
        inline GLenum get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Texture); }
        inline void bind() const { glBindTexture(m_type, m_id); }
        inline void unbind() const { glBindTexture(m_type, 0); }
        inline void bind_unit(GLuint unit) const { glBindTextureUnit(unit, m_id); }

    public:
        void create(GLenum type);
        void destroy();

    public:
        inline void generate_mipmap() { glGenerateTextureMipmap(m_id); }
        inline void set_wrap_s(GLenum wrap = GL_MIRRORED_REPEAT) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, wrap); }
        inline void set_wrap_t(GLenum wrap = GL_MIRRORED_REPEAT) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, wrap); }
        inline void set_wrap_r(GLenum wrap = GL_MIRRORED_REPEAT) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_R, wrap); }
        inline void set_min_filter(GLenum filter = GL_LINEAR) { glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, filter); }
        inline void set_mag_filter(GLenum filter = GL_LINEAR) { glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, filter); }

    public:
        template <typename T>
        void set_parameter(GLenum pname, T param);
        template <typename T>
        T get_parameter(GLenum pname) const;
        void set_border_color(const glm::vec4 &color);
        glm::vec4 get_border_color() const;
    };

} // namespace gl_wrapper
