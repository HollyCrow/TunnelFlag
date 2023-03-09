//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_CAMERA_H
#define TUNNELFLAG_CAMERA_H
#include <SDL2/SDL.h>

#include "../utils/vector2.h"


class Camera{
public:
    float scale = 2;
    bool close = false;

    Camera();

    void rescale_window(int, int);

    void draw_game();

private:
    Vector2 modifier;
    SDL_Rect p;
};


#endif //TUNNELFLAG_CAMERA_H
