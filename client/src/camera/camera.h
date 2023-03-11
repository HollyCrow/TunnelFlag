//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_CAMERA_H
#define TUNNELFLAG_CAMERA_H

#include <SDL2/SDL.h>

#include "../utils/vector2.h"
#include "../utils/color.h"


class Camera {
public:
    float scale = 2;
    bool close = false;
    SDL_Rect rect{};


    Camera();

    void rescale_window(int, int);

    void draw_game();

    static void set_color(Color);

    void draw_background(Vector2);

    void draw_players(Vector2);

    void draw_local_player(Vector2);

    void draw_map(Vector2);


};


#endif //TUNNELFLAG_CAMERA_H
