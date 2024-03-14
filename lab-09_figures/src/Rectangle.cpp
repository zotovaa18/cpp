#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int id, int x, int y, int height, int width) : Figure(id, x, y), height(height), width(width) {}

Rectangle::~Rectangle() {}

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
}

bool Rectangle::is_inside(int x, int y) const {
    //return (x <= this->x + width/2 && x >= this->x - width/2 && y <= this->y + height/2 && y >= this->y - height/2); 
    return (x <= this->x + width && x >= this->x && y <= this->y + height && y >= this->y); 
}

void Rectangle::zoom(int factor) {
    height *= factor;
    width *= factor;
}


