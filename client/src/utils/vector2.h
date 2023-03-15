//
// Created by holly on 15/03/23.
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

    Vector2 get_add(double x, double y);

    Vector2 get_add(Vector2 addition);

    void minus(double x, double y);

    void minus(Vector2 addition);

    Vector2 get_minus(double x, double y);

    Vector2 get_minus(Vector2 addition);


    double distance(double x, double y);

    double distance(Vector2 addition);

    Vector2 get_multiple(float);

    static Vector2 random_vector2(float);
};

#endif //TUNNELFLAG_VECTOR2_H
