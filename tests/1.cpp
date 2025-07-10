#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <base/core/read_string.hpp>
#include <glfw_wrapper/glfw_wrapper.hpp>
#include "../gl_wrapper/gl_wrapper.hpp"

void on_framebuffer_resize(GLFWwindow *window, int width, int height);

int main()
{
    //  初始化GLFW与OpenGL
    
    auto &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    auto &context = glfw_wrapper::Context::get_instance();

    glfw_wrapper::Window::set_opengl(true);
    auto window = glfw_wrapper::Window(glm::ivec2(512, 512));
    glfwSetFramebufferSizeCallback(window, on_framebuffer_resize);
    window.make_context_current();

    gl_wrapper::GLLoader loader;
    auto &debug_message_callback = gl_wrapper::DebugMessageCallback::get_instance();

    // 加载着色器

    gl_wrapper::Shader vshader(GL_VERTEX_SHADER);
    vshader.set_source(base::read_string_from_file("shaders/1.vert"));
    vshader.compile_shader();
    std::cout << "vertex shader source:" << std::endl
              << vshader.get_source() << std::endl
              << std::endl;
    gl_wrapper::Shader fshader(GL_FRAGMENT_SHADER);
    fshader.set_source(base::read_string_from_file("shaders/1.frag"));
    fshader.compile_shader();
    std::cout << "fragment shader source:" << std::endl
              << fshader.get_source() << std::endl
              << std::endl;
    gl_wrapper::Program program;
    program.attach_shader(vshader);
    program.attach_shader(fshader);
    program.link_program();

    // 创建顶点数组

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
    gl_wrapper::Buffer vbo(GL_ARRAY_BUFFER);
    {
        gl_wrapper::ScopedBinder sb(&vao, nullptr);

        vbo.bind();
        vbo.set_data(vertices);

        vao.set_vertex_attrib<glm::vec3>(0, 3 * sizeof(glm::vec3));
        vao.enable_vertex_attrib_array(0);
        vao.set_vertex_attrib<glm::vec3>(1, 3 * sizeof(glm::vec3), sizeof(glm::vec3));
        vao.enable_vertex_attrib_array(1);
        vao.set_vertex_attrib<glm::vec3>(2, 3 * sizeof(glm::vec3), 2 * sizeof(glm::vec3));
        vao.enable_vertex_attrib_array(2);
    }

    // 加载纹理

    int width, height;
    stbi_uc *pixels = stbi_load("assets/wall.jpg", &width, &height, nullptr, 0);
    if (!pixels)
        throw "Failed to load image";

    gl_wrapper::Texture2D texture;
    {
        gl_wrapper::ScopedBinder sb(&texture, nullptr);
        texture.set_wrap_s();
        texture.set_wrap_t();
        texture.set_min_filter();
        texture.set_mag_filter();
        texture.tex_image2D(GL_RGB, width, height, GL_RGB, pixels);
        texture.generate_mipmap();

        stbi_image_free(pixels);
        texture.set_border_color(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
        glm::vec4 color = texture.get_border_color();
        std::cout << "border color:" << std::endl
                  << color.r << ", " << color.g << ", " << color.b << ", " << color.a << std::endl
                  << std::endl;
    }

    // 创建帧缓冲

    gl_wrapper::Texture2D color_texture;
    {
        gl_wrapper::ScopedBinder sb(&color_texture, nullptr);
        color_texture.tex_image2D(GL_RGBA, 512, 512, GL_RGBA);
    }
    gl_wrapper::Renderbuffer rbo;
    {
        gl_wrapper::ScopedBinder sb(&rbo, nullptr);
        rbo.set_storage(GL_DEPTH24_STENCIL8, 512, 512);
    }
    gl_wrapper::Framebuffer fbo(GL_FRAMEBUFFER);
    {
        gl_wrapper::ScopedBinder sb(&fbo, nullptr);
        fbo.attach_color_texture(color_texture);
        fbo.attach_renderbuffer(GL_DEPTH_STENCIL_ATTACHMENT, rbo);
        std::cout << "is framebuffer complete: " << (fbo.check_status() == GL_FRAMEBUFFER_COMPLETE) << std::endl
                  << std::endl;
    };

    // 渲染到帧缓冲

    {
        gl_wrapper::ScopedBinder sb1(&fbo, nullptr);
        gl_wrapper::ScopedBinder sb2(&texture, nullptr);
        gl_wrapper::ScopedBinder sb3(&vao, nullptr);
        gl_wrapper::ScopedBinder sb4(&program, nullptr);

        glViewport(0, 0, 512, 512);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        vao.draw_arrays(GL_TRIANGLES, 3);

        std::cout << "successfully drawn a triangle" << std::endl
                  << std::endl;
    }

    // 保存到图像

    {
        gl_wrapper::ScopedBinder sb(&fbo, nullptr);
        auto framebuffer_pixels = fbo.read_pixels_as_RGBA(0, 0, 512, 512);
        int success = stbi_write_png("triangle.png", 512, 512, 4, framebuffer_pixels.data(), 0);
        std::cout << "save image: " << success << std::endl
                  << std::endl;
    }

    return 0;
}

void on_framebuffer_resize(GLFWwindow *window, int width, int height)
{
    std::cout << "on framebuffer resized, width: " << width << ", height: " << height << std::endl;
    glViewport(0, 0, width, height);
}
