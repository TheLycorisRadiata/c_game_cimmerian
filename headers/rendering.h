#ifndef __RENDERING_H__
#define __RENDERING_H__

#ifndef __GLEW_H__
#define __GLEW_H__
#include <GL/glew.h>
#endif

extern float player_speed[3];

void render_mesh(const MeshStruct* mesh, const GLenum drawing_mode);

void render_main_menu(void);
void render_game(void);

void move_player(void);
void straighten_pitch(void);
void set_pitch_back(void);

#endif

