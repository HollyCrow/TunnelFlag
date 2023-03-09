//
// Created by holly on 09/03/23.
//

#include "object.h"
#include "../utils/vector2.h"
#include "../utils/color.h"

Object::Object() {
    this->position = Vector2(0, 0);
    this->movable = false;
}
Object::Object(Vector2 start_position, bool movable) {
    this->position = start_position;
    this->movable = movable;
}

Vector2 Object::get_position(){
    return this->position;
}
void Object::set_position(Vector2 new_position){
    this->position = new_position;
}
void Object::move(Vector2 addition){
    this->position.add(addition);
}