//
// Created by holly on 09/03/23.
//

#ifndef TUNNELFLAG_VECTOR2_H
#define TUNNELFLAG_VECTOR2_H

class Vector2{
public:
    double x;
    double y;

    Vector2();
    Vector2(double x, double y);

    void add(double x, double y);

    void add(Vector2 addition);

    double distance(double x, double y);

    double distance(Vector2 addition);
};


#endif //TUNNELFLAG_VECTOR2_H
