#include "../headers/draw_test.h"
#include "../headers/draw.h"
#include "../headers/colors.h"
#include "../headers/maths.h"

void draw_test_corners(Texture* t)
{
    Vertex v;

    /* Bottom left */
    v.coords.x = 0;
    v.coords.y = 0;
    v.color = colors[COLOR_WHITE];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Top left */
    v.coords.x = 0;
    v.coords.y = get_coord_y(t, 1);
    v.color = colors[COLOR_RED];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Top right */
    v.coords.x = get_coord_x(t, 1);
    v.coords.y = get_coord_y(t, 1);
    v.color = colors[COLOR_GREEN];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Bottom right */
    v.coords.x = get_coord_x(t, 1);
    v.coords.y = 0;
    v.color = colors[COLOR_BLUE];
    draw_point(t, v.color, v.coords.x, v.coords.y);
    return;
}

void draw_test_center(Texture* t)
{
    Vertex v;

    /* Bottom left */
    v.coords.x = get_coord_x(t, 0.5f);
    v.coords.y = get_coord_y(t, 0.5f);
    v.color = colors[COLOR_WHITE];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Top left */
    v.coords.x = get_coord_x(t, 0.5f);
    v.coords.y = get_coord_y(t, 0.5f) + 1;
    v.color = colors[COLOR_RED];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Top right */
    v.coords.x = get_coord_x(t, 0.5f) + 1;
    v.coords.y = get_coord_y(t, 0.5f) + 1;
    v.color = colors[COLOR_GREEN];
    draw_point(t, v.color, v.coords.x, v.coords.y);

    /* Bottom right */
    v.coords.x = get_coord_x(t, 0.5f) + 1;
    v.coords.y = get_coord_y(t, 0.5f);
    v.color = colors[COLOR_BLUE];
    draw_point(t, v.color, v.coords.x, v.coords.y);
    return;
}

void draw_test_lines(Texture* t)
{
    Vertex v1, v2;

    v1.color = colors[COLOR_GREEN];
    v2.color = colors[COLOR_GREEN];

    v1.coords.x = get_coord_x(t, 0.5f) + 5;
    v1.coords.y = get_coord_y(t, 0.5f) + 5;
    v2.coords.x = v1.coords.x + 200;
    v2.coords.y = v1.coords.y + 100;
    draw_line(t, v1, v2);

    v1.color = colors[COLOR_RED];
    v2.color = colors[COLOR_RED];

    v1.coords.x -= NORMALIZE(v2.coords.x - v1.coords.x)*2;
    v1.coords.y -= NORMALIZE(v2.coords.y - v1.coords.y)*2;
    if (!is_coord_out_of_bounds(t->width, v1.coords.x) 
        && !is_coord_out_of_bounds(t->height, v1.coords.y))
        draw_point(t, v1.color, v1.coords.x, v1.coords.y);

    v2.coords.x -= NORMALIZE(v1.coords.x - v2.coords.x)*2;
    v2.coords.y -= NORMALIZE(v1.coords.y - v2.coords.y)*2;
    if (!is_coord_out_of_bounds(t->width, v2.coords.x) 
        && !is_coord_out_of_bounds(t->height, v2.coords.y))
        draw_point(t, v2.color, v2.coords.x, v2.coords.y);
    return;
}

void draw_test_rectangles(Texture* t)
{
    Vertex v1, v2;

    v1.coords.x = get_coord_x(t, 0.1f) - 1;
    v1.coords.y = get_coord_y(t, 0.33f) - 1;
    v1.color = colors[COLOR_WHITE];
    draw_rectangle(t, 1, v1, 100, 100);

    v2.coords.x = get_coord_x(t, 0.1f);
    v2.coords.y = get_coord_y(t, 0.33f) - 2;
    v2.color = colors[COLOR_RED];
    draw_rectangle(t, 0, v2, 100, 100);

    return;
}

void draw_test_circles(Texture* t)
{
    int radius = 100;
    Vertex v;
    v.color = colors[COLOR_BLUE];
    v.coords.x = get_coord_x(t, 0.7f);
    v.coords.y = get_coord_y(t, 0.4f);
    draw_circle(t, 1, v, radius);

    v.color = colors[COLOR_WHITE];
    draw_circle(t, 0, v, radius);
    return;
}

void draw_test_shapes(Texture* t)
{
    int full = 1;

    /* Convex (triangle) */
    Vertex v[3];
    v[0].color = colors[0];
    v[1].color = v[0].color;
    v[2].color = v[0].color;

    v[0].coords.x = get_coord_x(t, 0.25f);
    v[0].coords.y = get_coord_y(t, 0.25f);
    v[1].coords.x = get_coord_x(t, 0.50f);
    v[1].coords.y = get_coord_y(t, 0.75f);
    v[2].coords.x = get_coord_x(t, 0.75f);
    v[2].coords.y = get_coord_y(t, 0.25f);

    /* Concave and self-intercepting */
    /*
    Vertex v[5];
    v[0].color = colors[0];
    v[1].color = v[0].color;
    v[2].color = v[0].color;
    v[3].color = v[0].color;
    v[4].color = v[0].color;

    v[0].coords.x = get_coord_x(t, 0.25f);
    v[0].coords.y = get_coord_y(t, 0.25f);
    v[1].coords.x = get_coord_x(t, 0.50f);
    v[1].coords.y = get_coord_y(t, 0.75f);
    v[2].coords.x = get_coord_x(t, 0.30f);
    v[2].coords.y = get_coord_y(t, 0.44f);
    v[3].coords.x = get_coord_x(t, 0.75f);
    v[3].coords.y = get_coord_y(t, 0.25f);
    v[4].coords.x = get_coord_x(t, 0.50f);
    v[4].coords.y = get_coord_y(t, 0.10f);
    */

    draw_shape(t, full, v, sizeof(v)/sizeof(v[0]));
    return;
}

void draw_test_gradient_line(Texture* t)
{
    int i;
    int dist = 200;
    int half_dist = dist/2;
    float perc = 0;
    GLuint first_color, second_color, color_change;
    Vector v;
    v.x = get_coord_x(t, 0.1f);
    v.y = get_coord_x(t, 0.4f);

    first_color = *colors[COLOR_RED];
    second_color = *colors[COLOR_GREEN];
    color_change = 0;

    if (first_color - second_color)
    {
        perc = 100.0f / dist;

        set_red_channel(&color_change, (get_red_channel(second_color) 
            - get_red_channel(first_color)) / 50.0f * perc);
        set_green_channel(&color_change, (get_green_channel(second_color) 
            - get_green_channel(first_color)) / 50.0f * perc);
        set_blue_channel(&color_change, (get_blue_channel(second_color) 
            - get_blue_channel(first_color)) / 50.0f * perc);
        set_alpha_channel(&color_change, (get_alpha_channel(second_color) 
            - get_alpha_channel(first_color)) / 50.0f * perc);
    }
    for (i = 0; i < half_dist; ++i)
    {
        draw_point(t, &first_color, v.x, v.y);
        ++v.x;

        set_red_channel(&first_color, CLAMP(get_red_channel(first_color) 
            + get_red_channel(color_change), 0, 255));
        set_green_channel(&first_color, CLAMP(get_green_channel(first_color) 
            + get_green_channel(color_change), 0, 255));
        set_blue_channel(&first_color, CLAMP(get_blue_channel(first_color) 
            + get_blue_channel(color_change), 0, 255));
        set_alpha_channel(&first_color, CLAMP(get_alpha_channel(first_color) 
            + get_alpha_channel(color_change), 0, 255));
    }

    if (perc > 0)
    {
        set_red_channel(&color_change, (get_red_channel(first_color) 
            - get_red_channel(second_color)) / 50.0f * perc);
        set_green_channel(&color_change, (get_green_channel(first_color) 
            - get_green_channel(second_color)) / 50.0f * perc);
        set_blue_channel(&color_change, (get_blue_channel(first_color) 
            - get_blue_channel(second_color)) / 50.0f * perc);
        set_alpha_channel(&color_change, (get_alpha_channel(first_color) 
            - get_alpha_channel(second_color)) / 50.0f * perc);
    }
    for (; i < dist; ++i)
    {
        draw_point(t, &first_color, v.x, v.y);
        ++v.x;

        set_red_channel(&first_color, CLAMP(get_red_channel(first_color) 
            - get_red_channel(color_change), 0, 255));
        set_green_channel(&first_color, CLAMP(get_green_channel(first_color) 
            - get_green_channel(color_change), 0, 255));
        set_blue_channel(&first_color, CLAMP(get_blue_channel(first_color) 
            - get_blue_channel(color_change), 0, 255));
        set_alpha_channel(&first_color, CLAMP(get_alpha_channel(first_color) 
            - get_alpha_channel(color_change), 0, 255));
    }
    return;
}

void draw_test_gradient(Texture* t)
{
    Vertex v;
    GLuint color;

    set_blue_channel(&color, 255/2);
    set_alpha_channel(&color, 255);
    v.color = &color;

    for (v.coords.y = 0; v.coords.y < t->height; ++v.coords.y)
    {
        for (v.coords.x = 0; v.coords.x < t->width; ++v.coords.x)
        {
            set_red_channel(&color, v.coords.x * 255 / t->width);
            set_green_channel(&color, v.coords.y * 255 / t->height);
            draw_point(t, v.color, v.coords.x, v.coords.y);
        }
    }
    return;
}

/* 64 colors */
void draw_8bit_rgb_palette(Texture* t)
{
    /*
       0 =   0 = 0x00
       1 =  85 = 0x55
       2 = 170 = 0xAA
       3 = 255 = 0xFF
    */

    const int root = 8;
    const int square_size_x = t->width / root;
    const int square_size_y = t->height / root;
    int col, row;

    int i;
    int r, g, b;

    GLuint c[64] = {0};
    Vertex v;

    i = 0;
    col = 0;
    row = 0;
    for (r = 0; r < 4; ++r)
    {
        for (g = 0; g < 4; ++g)
        {
            for (b = 0; b < 4; ++b)
            {
                set_red_channel(&c[i], r * 255 / 3);
                set_green_channel(&c[i], g * 255 / 3);
                set_blue_channel(&c[i], b * 255 / 3);
                set_alpha_channel(&c[i], 255);

                /**/
                v.coords.x = col * square_size_x;
                v.coords.y = row * square_size_y;
                v.color = &c[i];
                draw_rectangle(t, 1, v, square_size_x, square_size_y);

                v.color = colors[COLOR_WHITE];
                draw_rectangle(t, 0, v, square_size_x, square_size_y);

                ++col;
                if (!(col % root))
                {
                    col = 0;
                    ++row;
                }
                /**/

                /*
                printf("Color n°%d: (%d, %d, %d, %d)\n", i+1, 
                    get_red_channel(c[i]), 
                    get_green_channel(c[i]), 
                    get_blue_channel(c[i]), 
                    get_alpha_channel(c[i]));
                */

                ++i;
            }
        }
    }
    return;
}

/* 190 colors */
void draw_8bit_rgba_palette(Texture* t)
{
    /*
       0 =   0 = 0x00
       1 =  85 = 0x55
       2 = 170 = 0xAA
       3 = 255 = 0xFF
    */

    /*
        256 different possible combinations, but 4*16 are alpha 0, so they're 
        black. We're down to 192 colors.

        Then, here are the first four colors of the original 256 set, all black:
        - Color n°1: (0, 0, 0, 0)
        - Color n°2: (0, 0, 0, 85)
        - Color n°3: (0, 0, 0, 170)
        - Color n°4: (0, 0, 0, 255)
        Keep only one, logically the first one, which is alpha 0. Now it's 190.
    */

    const int root = 16; /* Root of 256 */
    const int square_size_x = t->width / root;
    const int square_size_y = t->height / root;
    int col, row;

    int i;
    int r, g, b, a;

    GLuint c[190] = {0};
    Vertex v;

    i = 0;
    col = 0;
    row = 0;
    for (r = 0; r < 4; ++r)
    {
        for (g = 0; g < 4; ++g)
        {
            for (b = 0; b < 4; ++b)
            {
                for (a = 0; a < 4; ++a)
                {
                    set_red_channel(&c[i], r * 255 / 3);
                    set_green_channel(&c[i], g * 255 / 3);
                    set_blue_channel(&c[i], b * 255 / 3);
                    set_alpha_channel(&c[i], a * 255 / 3);

                    v.coords.x = col * square_size_x;
                    v.coords.y = row * square_size_y;
                    ++col;
                    if (!(col % root))
                    {
                        col = 0;
                        ++row;
                    }

                    if ((i && !get_red_channel(c[i]) && !get_green_channel(c[i]) && !get_blue_channel(c[i]))
                        || (i && !get_alpha_channel(c[i])))
                    {
                        v.color = &c[0]; /* Black */ 
                        draw_rectangle(t, 1, v, square_size_x, square_size_y);
                    }
                    else
                    {
                        v.color = &c[i];
                        draw_rectangle(t, 1, v, square_size_x, square_size_y);

                        v.color = colors[COLOR_WHITE];
                        draw_rectangle(t, 0, v, square_size_x, square_size_y);

                        ++i;
                    }
                }
            }
        }
    }

    /*
    printf("------------\n");
    for (i = 0; i < 190; ++i)
        printf("Color n°%d: (%d, %d, %d, %d)\n", i+1, 
            get_red_channel(c[i]), 
            get_green_channel(c[i]), 
            get_blue_channel(c[i]), 
            get_alpha_channel(c[i]));
    */
    return;
}

