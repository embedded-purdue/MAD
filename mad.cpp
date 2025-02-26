#include "conways.hpp"

int main(int argc, char **argv) {

    float density = argc > 1 ? std::stof(argv[1]) : 0.4;
    
    Conways display(density);
    display.simulate(120);

    return 0;

}