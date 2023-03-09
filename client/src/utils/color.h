//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_COLOR_H
#define TUNNELFLAG_COLOR_H

/*
 * # Color
 * ### Simple class to store a color in rgba format
 *
 * ## Parameters
 * ### uint8_t r: red value
 * ### uint8_t g: green value
 * ### uint8_t b: blue value
 * ### uint8_t a: alpha value
 */

#include <cstdint>


class Color{
public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color(uint8_t, uint8_t, uint8_t, uint8_t);


    int,int,int,int get_color()
};



#endif //TUNNELFLAG_COLOR_H
