#include "Scheme.hpp"

Scheme::Scheme(int capacity) {
    figures_ = new Figure* [capacity];
    capacity_ = capacity;
    count_ = 0; 
}

Scheme::~Scheme() {
    for (int i = 0; i < count_; i++) {
        delete figures_[i];
    }
    delete[] figures_;
}

void Scheme::push_back_figure(Figure* fg) {
    if (count_ < capacity_) {
        figures_[count_] = fg;
        count_++;
    }
}

void Scheme::remove_figure(int id) {
    int ind = -1;
    for (int i = 0; i < count_; i++) {
        if (figures_[i]->get_id() == id) {
            ind = i;
            break;
        } 
    }
    if (ind != -1) {
        delete figures_[ind];
        for (int i = ind; i < count_ - 1; i++) {
            figures_[i] = figures_[i + 1];
        }
        count_ --;
    }
}

void Scheme::print_all_figures() {
    for (int i = 0; i < count_; i++) {
        figures_[i]->print();
    } 
}

void Scheme::zoom_figure(int id, int factor) {
    for (int i = 0; i < count_; i++) {
        if (figures_[i]->get_id() == id) {
            figures_[i]->zoom(factor);
            break;
        } 
    }
}

Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < count_; i++) {
        if (figures_[i]->is_inside(x, y)) {
            return figures_[i];
        }
    }
    return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
    for (int i = 0; i < count_; i++) {
        if (figures_[i]->get_id() == id) {
            figures_[i]->move(new_x, new_y);
            break;
        } 
    }
}
