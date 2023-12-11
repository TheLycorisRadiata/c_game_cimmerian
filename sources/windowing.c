#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../headers/windowing.h"

#define MIN(a, b) (a < b ? a : b)
#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480
#define ASPECT_RATIO (16.0f / 9.0f)

static void set_aspect_ratio_viewport(int width, int height)
{
    int new_width = width;
    int new_height = width / ASPECT_RATIO;
    int x_offset, y_offset;

    if (new_height > height)
    {
        new_height = height;
        new_width = height * ASPECT_RATIO;
    }

    x_offset = (width - new_width) / 2;
    y_offset = (height - new_height) / 2;

    glViewport(x_offset, y_offset, new_width, new_height);
    return;
}

static void set_initial_viewport(GLFWwindow* window)
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    set_aspect_ratio_viewport(width, height);
    return;
}

static void framebuffer_size_callback
(
    __attribute__((unused))GLFWwindow* window, 
    int width, 
    int height
)
{
    set_aspect_ratio_viewport(width, height);
    return;
}

GLFWwindow* get_window(const char* title)
{
    GLFWwindow* window;
    const GLFWvidmode* vid_mode;
    int window_size[2];

    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: The GLFW library failed to initialize.\n");
        exit(EXIT_FAILURE);
    }

    vid_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window_size[0] = MIN(WINDOW_DEFAULT_WIDTH, vid_mode->width);
    window_size[1] = MIN(WINDOW_DEFAULT_HEIGHT, vid_mode->height);

    #ifdef __APPLE__
    /* Window hints are to be called before creating the window */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    window = glfwCreateWindow(window_size[0], window_size[1], title, NULL, 
        NULL);
    if (!window)
    {
        fprintf(stderr, "ERROR: The window failed to create. The issue may "
            "be with the GLFW library, but comes more likely from the OpenGL "
            "library. Check that your drivers are properly installed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowSizeLimits(window, 
        /* min */ window_size[0], window_size[1], 
        /* max */ vid_mode->width, vid_mode->height);
    glfwMakeContextCurrent(window);
    set_initial_viewport(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* GLEW includes the latest version of OpenGL available on the machine */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) /* GLEW_OK is zero */
    {
        fprintf(stderr, "ERROR: The GLEW library failed to initialize.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    return window;
}

int get_glsl_version(void)
{
    /*
        GLSL (OpenGL Shader Language)
        -----------------------------------------------------------------------
        There is a deprecated way to render graphics in OpenGL, but the modern 
        way is to use shaders. There are two sorts: vertex shader (shape) and 
        fragment shader (color). They are written in a language called GLSL, 
        and are stored in a *.glsl text file, although it's possible to simply 
        hardcode them in the source code, as they'll end up in a string anyway 
        once the file is processed.

        No matter the type of shader, its first line is the GLSL version, like 
        so: "#version 400\n". The GLSL version depends on OpenGL's version, so 
        this line has to be changed accordingly or there can be issues.

        - OpenGL 4 and above   --> GLSL 400
        - OpenGL 3.3           --> GLSL 330
        - OpenGL 3.2 and below --> GLSL 150
    */

    const unsigned char* gl = glGetString(GL_VERSION); /* 4.6.0 ... */

    if (gl[0]-48 >= 4)
        return 400;
    else if (gl[0]-48 == 3 && gl[2]-48 == 3)
        return 330;
    else
        return 150;
}

