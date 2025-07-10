#include <iostream>
#include "application.hpp"

class Test2 : public Application
{
private:
    gl_wrapper::Program normal_shader;
    gl_wrapper::Program shadow_shader;
    gl_wrapper::VertexArray plane_vao;

private:
    void _create_plane_vao()
    {
        gl_wrapper::ScopedBinder sb(&plane_vao, nullptr);
    }

    void _load_shaders()
    {
        normal_shader = load_program_from_file("shaders/2_normal.vert", "shaders/2_normal.frag");
        shadow_shader = load_program_from_file("shaders/2_shadow.vert", "shaders/2_shadow.frag");
    }

protected:
    void _initialize() override
    {
        gl_wrapper::DebugMessageCallback::get_instance();

        _create_plane_vao();
        _load_shaders();
    }

    void _draw() override
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gl_wrapper::ScopedBinder sb(&plane_vao, nullptr);

        {
            gl_wrapper::ScopedBinder sb2(&shadow_shader);
        }

        {
            gl_wrapper::ScopedBinder sb2(&normal_shader);
        }
    }
};

int main()
{
    Test2 app;
    app.run();
    return app.get_exit_code();
}
