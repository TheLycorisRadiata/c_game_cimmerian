#ifndef __WINDOWING_H__
#define __WINDOWING_H__

GLFWwindow* get_window(const char* title);
void toggle_fullscreen(GLFWwindow* window);
int get_glsl_version(void);

#endif

