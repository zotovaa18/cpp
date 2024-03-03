#include "Circle.hpp"
#include <cstring>
#include <iostream>


Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y), radius(radius) {
    int size = strlen(label) + 1;
    this->label = new char[size];
    strcpy(this->label, label);
}

Circle::~Circle() {
    delete[] label;
}

void Circle::print() const {
    std::cout << "Circle " << id << ": x = " << x << " y = " << y << " radius = " << radius << " label = " << label << std::endl;
}

bool Circle::is_inside(int x, int y) const {
    int dx = x - this->x;
    int dy = y - this->y;
    
    return (dx*dx + dy*dy) <= (radius*radius);
}

void Circle::zoom(int factor) {
    radius = radius * factor;
}

