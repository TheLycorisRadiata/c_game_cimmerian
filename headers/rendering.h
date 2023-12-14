#ifndef __RENDERING_H__
#define __RENDERING_H__

void irm_triangle_white(void);
void irm_triangle_rgb(void);
void irm_rectangle_bicolor(void);
void irm_viewport_white(void);

GLuint create_mesh_vao(const GLfloat points[], const int points_len, 
    const int nbr_vertices, const GLenum usage);
GLuint compile_shader(const GLenum type, const char* filepath);
GLuint create_shader_program(const GLuint vs, const GLuint fs);

void render_mesh(const GLuint shader_program, const GLuint VAO, 
    const GLenum drawing_mode, const int nbr_vertices);

void free_mesh(const GLuint VAO);
void free_shader(const GLuint shader);
void free_shader_program(const GLuint shader_program);

#endif

