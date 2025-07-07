#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <base/core/read_string.hpp>
#include <glfw_wrapper/glfw_wrapper.hpp>
#include "../gl_wrapper/gl_wrapper.hpp"

void on_framebuffer_resize(GLFWwindow *window, int width, int height);

int main()
{
    auto &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    auto &context = glfw_wrapper::Context::get_instance();

    glfw_wrapper::Window::set_opengl(true);
    auto window = glfw_wrapper::Window(glm::ivec2(512, 512));
    glfwSetFramebufferSizeCallback(window.get_window(), on_framebuffer_resize);

    window.make_context_current();
    gl_wrapper::GLLoader loader;
    glViewport(0, 0, 512, 512);

    auto &debug_message_callback = gl_wrapper::DebugMessageCallback::get_instance();
    auto &gl_context = gl_wrapper::Context::get_instance();

    gl_wrapper::Shader vshader(GL_VERTEX_SHADER);
    vshader.shader_source(base::read_string_from_file("shaders/1.vert"));
    vshader.compile_shader();
    std::cout << vshader.get_source() << std::endl;
    gl_wrapper::Shader fshader(GL_FRAGMENT_SHADER);
    fshader.shader_source(base::read_string_from_file("shaders/1.frag"));
    fshader.compile_shader();
    std::cout << fshader.get_source() << std::endl;
    gl_wrapper::Program program;
    program.attach_shader(vshader);
    program.attach_shader(fshader);
    program.link_program();

    const std::vector<glm::vec3> vertices = {
        glm::vec3(0.0f, 0.5f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(0.5f, 0.0f, 0.0f),

        glm::vec3(-0.433f, -0.25f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0669f, 0.75f, 0.0f),

        glm::vec3(0.433f, -0.25f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.933f, 0.75f, 0.0f),
    };

    gl_wrapper::VertexArray vao;
    vao.bind();
    gl_wrapper::Buffer vbo(GL_ARRAY_BUFFER);
    vbo.bind();
    vbo.buffer_data(vertices);
    vao.vertex_attrib_pointer<glm::vec3>(0, 3 * sizeof(glm::vec3));
    vao.enable_vertex_attrib_array(0);
    vao.vertex_attrib_pointer<glm::vec3>(1, 3 * sizeof(glm::vec3), sizeof(glm::vec3));
    vao.enable_vertex_attrib_array(1);
    vao.vertex_attrib_pointer<glm::vec3>(2, 3 * sizeof(glm::vec3), 2 * sizeof(glm::vec3));
    vao.enable_vertex_attrib_array(2);
    vao.unbind();

    int width, height;
    stbi_uc *pixels = stbi_load("assets/wall.jpg", &width, &height, nullptr, 0);
    if (!pixels)
        throw "Failed to load image";

    gl_wrapper::Texture2D texture;
    texture.bind();
    texture.set_wrap_s();
    texture.set_wrap_t();
    texture.set_min_filter();
    texture.set_mag_filter();
    texture.tex_image2D(GL_RGB, width, height, GL_RGB, pixels);
    texture.generate_mipmap();
    stbi_image_free(pixels);
    texture.set_border_color(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
    glm::vec4 color = texture.get_border_color();
    std::cout << color.r << ", " << color.g << ", " << color.b << ", " << color.a << std::endl;

    while (!window.should_close())
    {
        context.poll_events();

        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        texture.bind();
        vao.bind();
        vao.draw_arrays(GL_TRIANGLES, 3);

        window.swap_buffers();
    }

    return 0;
}

void on_framebuffer_resize(GLFWwindow *window, int width, int height)
{
    std::cout << "on framebuffer resized, width: " << width << ", height: " << height << std::endl;
    glViewport(0, 0, width, height);
}
