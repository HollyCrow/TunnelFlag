//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_CAMERA_H
#define TUNNELFLAG_CAMERA_H
#include <SDL2/SDL.h>

#include "../utils/vector2.h"


class Camera{
public:
    float scale = 1;
    bool close = false;

    Camera();

    void rescale_window(int, int);

    void draw_game();


};


#endif //TUNNELFLAG_CAMERA_H
