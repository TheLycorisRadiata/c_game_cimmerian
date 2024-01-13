#ifndef __WINDOWING_H__
#define __WINDOWING_H__

#ifndef __STDIO_H__
#define __STDIO_H__
#include <stdio.h>
#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__
#include <stdlib.h>
#endif

#ifndef __GLEW_H__
#define __GLEW_H__
#include <GL/glew.h>
#endif

#ifndef __GLFW_H__
#define __GLFW_H__
#include <GLFW/glfw3.h>
#endif

typedef struct
{
    int width;
    int height;
    float aspect_ratio;
} MonitorSize;

extern MonitorSize monitor_size;

GLFWwindow* get_window(const char* title);
void toggle_fullscreen(GLFWwindow* window);

#endif

