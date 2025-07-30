#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glfw_wrapper/misc/main_loop.hpp>
#include "../gl_wrapper/gl_wrapper.hpp"

class MainLoop : public glfw_wrapper::MainLoop
{
private:
    static constexpr std::array<gl_wrapper::Vertex2DTex, 4> VERTICES = {
        gl_wrapper::Vertex2DTex{{-0.5f, 0.5f}, {0.0f, 0.0f}},
        gl_wrapper::Vertex2DTex{{-0.5f, -0.5f}, {0.0f, 1.0f}},
        gl_wrapper::Vertex2DTex{{0.5f, 0.5f}, {1.0f, 0.0f}},
        gl_wrapper::Vertex2DTex{{0.5f, -0.5f}, {1.0f, 1.0f}},
    };

    gl_wrapper::Program program;
    gl_wrapper::VertexArray vao;
    gl_wrapper::Texture2D texture;
    gl_wrapper::Sampler sampler;

protected:
    void _initialize() override
    {
        gl_wrapper::GLLoader();
        gl_wrapper::DebugMessageCallback::get_instance();
        glViewport(0, 0, 1152, 648);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        program = gl_wrapper::load_program_from_file("shaders/2.vert", "shaders/2.frag");
        vao = gl_wrapper::create_vertex_array_from_vertices(VERTICES);

        int width, height;
        stbi_uc *pixels = stbi_load("assets/wall.jpg", &width, &height, nullptr, 0);
        if (!pixels)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to load image");
        texture = gl_wrapper::create_texture_2d_from_pixels(
            gl_wrapper::InternalFormat::RGB8, width, height, gl_wrapper::PixelFormat::RGB, pixels);
        stbi_image_free(pixels);

        sampler = gl_wrapper::create_default_sampler();
    }

    void _draw() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        vao.bind();
        sampler.bind(0);
        texture.bind_unit(0);
        vao.draw_arrays(gl_wrapper::VertexArray::DrawMode::TriangleStrip, 4);
    }

public:
    MainLoop()
    {
        m_is_opengl_debug_context_enabled = true;
    }
};

int main()
{
    MainLoop app;
    app.run();
    return app.get_exit_code();
}
