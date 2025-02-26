#include "conways.hpp"

Conways::Conways(float d) : density(d) {
    initialize_display();
}

Conways::~Conways() {}

void Conways::initialize_display() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            display[y][x] = (rand() % 100) < density * 100 ? 1 : 0;
        }
    }
}

void Conways::calculate_next_display() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) { continue; }
                    if (pixel_is_valid(x + i, y + j) && display[y + j][x + i]) { 
                        neighbors++; 
                    }
                }
            }
            if (display[y][x]) {
                next_display[y][x] = ((neighbors == 2) || (neighbors == 3));
            } else {
                next_display[y][x] = (neighbors == 3);
            }
        }
    }
}

float Conways::get_density() {
    return density;
}
