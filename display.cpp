#include "display.hpp"

void Display::simulate(float frame_rate) {

    u_int DOT_SIZE = 6;
    u_int WINDOW_WIDTH = width * DOT_SIZE;
    u_int WINDOW_HEIGHT = height * DOT_SIZE;
    float PAUSE = 1.0 / frame_rate;

    initialize_display();

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "M.A.D Simulation");
    sf::CircleShape circle(DOT_SIZE / 2);
    sf::RectangleShape background({static_cast<float>(WINDOW_WIDTH), static_cast<float>(WINDOW_HEIGHT)});
    background.setFillColor(sf::Color(0x88, 0x88, 0x88, 0xFF));
    sf::Color color;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Pause for 1 second

    while(window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(background);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                color = display[y][x] ? sf::Color::White : sf::Color::Black;
                circle.setFillColor(color);
                circle.setPosition({static_cast<float>(x * DOT_SIZE), static_cast<float>(y * DOT_SIZE)});
                window.draw(circle);
            }
        }

        update();
        window.draw(circle);
        window.display();
        std::this_thread::sleep_for(std::chrono::duration<float>(PAUSE));
    }
}

void Display::update() { 
    calculate_next_display();
    display = next_display; 
};

bool Display::pixel_is_valid(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Display::calculate_next_display() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            next_display[y][x] = !display[y][x];
        }
    }
}

void Display::print_display() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << display[y][x];
        }
        std::cout << std::endl;
    }
}

int Display::height_get() { 
    return height; 
};

int Display::width_get() { 
    return width; 
};
