#include "Circle.hpp"
#include <cstring>
#include <cstdio>


Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y), radius_(radius) {
    int size = strlen(label) + 1;
    label_ = new char[size];
    strcpy(label_, label);
}

Circle::~Circle() {
    delete[] label_;
}

void Circle::print() const {
    std::printf("Circle %d: x = %d y = %d radius = %d label = %s\n", id_, x_, y_, radius_, label_);
}

bool Circle::is_inside(int x, int y) const {
    int dx = x - x_;
    int dy = y - y_;
    
    return ((dx*dx + dy*dy) <= (radius_*radius_));
}

void Circle::zoom(int factor) {
    radius_ *= factor;
}

