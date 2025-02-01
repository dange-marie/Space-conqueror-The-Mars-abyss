#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "level.hpp"

class Core
{
    public:
        Core() : window(sf::VideoMode(1900, 1000), "Mars Abyss"), level("assets/levels/desert.txt") {
            window.setFramerateLimit(60);
        }
        void run() {
            while (window.isOpen()) {
                processEvents();
                update();
                render();
            }
        }

    private:
        void processEvents() {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }

        void update() {
            
        }

        void render() {
            std::vector<std::vector<char>> tiles = level.getTiles();
            window.clear();
            for (int i = 0; i < tiles.size(); i++) {
                for (int j = 0; j < tiles[i].size(); j++) {
                    if (tiles[i][j] == '*') {
                        sf::RectangleShape tile(sf::Vector2f(12, 12));
                        tile.setPosition(j * 12 + 1600, i * 12);
                        if (tiles[i][j] == '*') {
                            tile.setFillColor(sf::Color::White);
                        } else {
                            tile.setFillColor(sf::Color::Black);
                        }
                        window.draw(tile);
                    }
                    if (tiles[i][j] == 'P') {
                        sf::CircleShape player(7.5);
                        player.setPosition(j * 15 + 1600, i * 15);
                        player.setFillColor(sf::Color::Green);
                        window.draw(player);
                    }
                }
            }
            window.display();
        }
    
        sf::RenderWindow window;
        Level level;
};
