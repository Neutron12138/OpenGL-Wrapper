#pragma once

#include <base/misc/application.hpp>
#include <base/core/read_string.hpp>
#include <glfw_wrapper/glfw_wrapper.hpp>
#include "../gl_wrapper/gl_wrapper.hpp"

class Application : public base::Application
{
protected:
    glfw_wrapper::Context &glfw_context = glfw_wrapper::Context::get_instance();
    glfw_wrapper::ErrorCallback &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    glfw_wrapper::WindowWithCallback window;

protected:
    virtual void _draw() {}

public:
    void run() override
    {
        glfw_wrapper::Window::set_opengl(true);
        window.create(glm::ivec2(1152, 648));
        window.make_context_current();
        gl_wrapper::GLLoader loader();
        gl_wrapper::DebugMessageCallback::get_instance();
        glViewport(0, 0, 1152, 648);

        _initialize();
        while (!is_should_quit() && !window.should_close())
        {
            glfw_context.poll_events();
            _draw();
            window.swap_buffers();
        }
        _finalize();
    }

    gl_wrapper::Program load_program_from_file(const std::string &vfilename, const std::string &ffilename)
    {
        gl_wrapper::Shader vs(GL_VERTEX_SHADER);
        vs.set_source(base::read_string_from_file(vfilename));
        vs.compile_shader();

        gl_wrapper::Shader fs(GL_FRAGMENT_SHADER);
        fs.set_source(base::read_string_from_file(ffilename));
        fs.compile_shader();

        gl_wrapper::Program program;
        program.attach_shader(vs);
        program.attach_shader(fs);
        program.link_program();

        return std::move(program);
    }
};
