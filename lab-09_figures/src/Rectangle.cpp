#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int id, int x, int y, int height, int width) : Figure(id, x, y), height(height), width(width) {}

Rectangle::~Rectangle() {}

void Rectangle::print() const {
    std::cout << "Rectangle " << id << ": x = " << x << " y = " << y << " width = " << width << " height = " << height << std::endl;
}

bool Rectangle::is_inside(int x, int y) const {
    return (x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + width);
}

void Rectangle::zoom(int factor) {
    height = height * factor;
    width = width * factor;
}


