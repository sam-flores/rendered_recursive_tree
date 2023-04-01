#include "FPToolkit.c"
#include "M3d_matrix_tools.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tree.c"
#include "light_model.c"
#include "shapes.c"
#include "graphics.c"
#include "create_tree_3D.c"
#include "inputs.c"

void create_scene()
{
    double pos[3] = {0, -.25, 0};
    double rot[3] = {0, 0, 0};
    double scl[3] = {.5, .5, .5};

    int num_branches = 50;
    scene.objects[0].head = init_tree(num_branches);
    TSR(pos, scl, rot, scene.objects[0].TSR, scene.objects[0].TSR_inverse);
    scene.objects[0].rgb[0] = 0;
    scene.objects[0].rgb[1] = 1;
    scene.objects[0].rgb[2] = 0;
    scene.objects[0].shape = tree;
    scene.num_objects++;
}

void update_scene()
{
    double pos[3] = {0, -.25, 0};
    double rot[3] = {0, screen.i_time, 0};
    double scl[3] = {.5, .5, .5};
    TSR(pos, scl, rot, scene.objects[0].TSR, scene.objects[0].TSR_inverse);
}

int main()
{

    init_screen(600, 600);
    G_init_graphics(screen.width, screen.height); // init graphics

    double camera_lens_angle = 30;
    set_camera_constants(screen.width, screen.height, camera_lens_angle);
    double v[3] = {0, 0, 1};
    set_camera(v);

    // create objects
    create_scene();

    int q = 0;
    // main loop
    while (q != 'q')
    {

        refresh_screen();

        // render tree
        render_tree(scene.objects[0]);
        update_scene();
        G_display_image();

        // check for user interaction
        q = G_no_wait_key();
        usleep(1000);
        get_key(q, v);
        set_camera(v);

        screen.i_time += M_PI;
    }
}