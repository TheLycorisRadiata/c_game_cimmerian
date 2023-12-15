#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../headers/windowing.h"
#include "../headers/input.h"
#include "../headers/rendering.h"

/*
float vertex_data_pos[] =
{
     0.0f,  0.5f,  0.0f, 
     0.5f, -0.5f,  0.0f, 
    -0.5f, -0.5f,  0.0f,
};
*/

float vertex_data[] =
{
    /* Position */          /* Color */
     0.0f,  0.5f,  0.0f,    1.0f, 0.0f, 0.0f, 
     0.5f, -0.5f,  0.0f,    0.0f, 1.0f, 0.0f, 
    -0.5f, -0.5f,  0.0f,    0.0f, 0.0f, 1.0f, 
};

static void list_arguments(int argc, char** argv)
{
    int i;
    printf("Debug: %d arguments\n", argc - 1);
    if (argc > 1)
    {
        for (i = 1; i < argc; ++i)
            printf("%d. %s\n", i, argv[i]);
    }
    return;
}

int main(int argc, char** argv)
{
    const char* title = "Cimmerian";
    GLFWwindow* window = get_window(title);

    const int nbr_attributes = 2;
    const int vertex_data_length = sizeof(vertex_data)/sizeof(float);
    const int nbr_vertices = vertex_data_length / 3 / nbr_attributes;
    const int glsl_version = get_glsl_version();
    const char* vs_filepath = "shaders/vs.glsl";
    const char* fs_filepath = "shaders/fs.glsl";
    GLuint vao, vs, fs, shader_program;
    UniformStruct uniform_struct;

    glfwSetKeyCallback(window, physical_key_callback);
    /* glfwSetCharCallback(window, char_key_callback); */

    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    vao = create_mesh_vao(vertex_data, vertex_data_length, nbr_attributes, 
        GL_STATIC_DRAW);

    vs = compile_shader(GL_VERTEX_SHADER, vs_filepath, glsl_version);
    fs = compile_shader(GL_FRAGMENT_SHADER, fs_filepath, glsl_version);
    shader_program = create_shader_program(vs, fs);
    if (!shader_program)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        fprintf(stderr, "ERROR: Couldn't compile shader program from \"%s\" "
            "vertex shader and \"%s\" fragment shader.\n", vs_filepath, 
            fs_filepath);
    }
    /*
        The shaders are already compiled in the shader program, so no need to 
        keep them around unless you want to use them in another shader program.
    */
    free_shader(vs);
    free_shader(fs);
    uniform_struct = init_uniform(shader_program, "single_color", UNIFORM_3F, 
        0.8f, 0.21f, 0.0f, 0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /*
        uniform_struct.z = 0.5f;
        */
        render_mesh(shader_program, &uniform_struct, vao, GL_TRIANGLES, 
            nbr_vertices);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free_mesh(vao);
    free_shader_program(shader_program);
    glfwTerminate();

    list_arguments(argc, argv);
    return EXIT_SUCCESS;
}

