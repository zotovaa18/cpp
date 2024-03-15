#include "Circle.hpp"
#include <cstring>
#include <stdio.h>


Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y), radius(radius) {
    int size = strlen(label) + 1;
    this->label = new char[size];
    strcpy(this->label, label);
}

Circle::~Circle() {
    delete[] label;
}

void Circle::print() const {
    printf("Circle %d: x = %d y = %d radius = %d label = %s\n", id, x, y, radius, label);
}

bool Circle::is_inside(int x, int y) const {
    int dx = x - this->x;
    int dy = y - this->y;
    
    return (dx*dx + dy*dy) <= (radius*radius);
}

void Circle::zoom(int factor) {
    radius *= factor;
}

