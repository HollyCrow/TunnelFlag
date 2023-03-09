//
// Created by holly on 09/03/23.
//

#include "color.h"
#include <cstdint>

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
    this->a = a;
    this->r = r;
    this->g = g;
    this->b = b;
}