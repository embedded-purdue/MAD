#ifndef DISPLAY_H
#define DISPLAY_H

#include <array>
#include <optional>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <thread>
#include <chrono>

class Display {
public:
    virtual void calculate_next_display() = 0;
    virtual void initialize_display() = 0;
    void simulate(float frame_rate = 1.0);
    void update();
    bool pixel_is_valid(int x, int y);
    void print_display();
    int height_get();
    int width_get();
protected:
    static constexpr u_int height = 64 * 2;
    static constexpr u_int width = 96 * 2;
    std::array<std::array<bool, width>, height> display;
    std::array<std::array<bool, width>, height> next_display;
};


#endif // DISPLAY_H