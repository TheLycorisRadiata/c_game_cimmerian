#ifndef __DRAW_H__
#define __DRAW_H__

#ifndef __GLEW_H__
#define __GLEW_H__
#include <GL/glew.h>
#endif

#include "textures.h"
#include "colors.h"
#include "coords.h"

typedef struct
{
    Vector coords;
    GLubyte color;
} Vertex;

void draw_point(Texture* t, GLubyte color, int x, int y);
void draw_point_unsafe(Texture* t, GLubyte color, int x, int y);
void draw_line(Texture* t, Vertex v1, Vertex v2);
void draw_line_unsafe(Texture* t, Vertex v1, Vertex v2);
void draw_line_horizontal(Texture* t, Vertex v, int last_x);
void draw_line_horizontal_unsafe(Texture* t, Vertex v, int last_x);
void draw_line_vertical(Texture* t, Vertex v, int last_y);
void draw_line_vertical_unsafe(Texture* t, Vertex v, int last_y);
void draw_line_diagonal(Texture* t, Vertex v, Vector dir);
void draw_line_diagonal_unsafe(Texture* t, Vertex v, Vector dir);
void draw_rectangle(Texture* t, int full, Vertex v, int width, int height);
void draw_rectangle_unsafe(Texture* t, int full, Vertex v, int width, 
    int height);
void draw_rectangle_full_unsafe(Texture* t, Vertex v, int width, int height);
void draw_rectangle_empty_unsafe(Texture* t, Vertex v, int width, int height);
void draw_circle(Texture* t, int full, Vertex v, int radius);
void draw_circle_unsafe(Texture* t, int full, Vertex v, int radius);
void draw_circle_full_unsafe(Texture* t, Vertex center, int radius);
void draw_circle_empty_unsafe(Texture* t, Vertex center, int radius);
void draw_shape(Texture* t, int full, Vertex arr[], int len);
void draw_shape_unsafe(Texture* t, int full, Vertex arr[], int len);
void draw_shape_full_unsafe(Texture* t, Vertex arr[], int len);

#endif

