#include "Rectangle.hpp"
#include <stdio.h>

Rectangle::Rectangle(int id, int x, int y, int height, int width) : Figure(id, x, y), height_(height), width_(width) {}

Rectangle::~Rectangle() {}

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id_, x_, y_, width_, height_);
}

bool Rectangle::is_inside(int x, int y) const {
    return (x <= x_ + width_/2 && x >= x_ - width_/2 && y <= y_ + height_/2 && y >= y_ - height_/2); 
}

void Rectangle::zoom(int factor) {
    height_ *= factor;
    width_ *= factor;
}


