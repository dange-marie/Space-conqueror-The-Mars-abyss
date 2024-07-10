#pragma once
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "sfml_ui.hpp"
#include <string.h>
#include <unistd.h>
#include <filesystem>
#include "level.hpp"
#include "player.hpp"
#include "vector.hpp"
#include "point.hpp"

namespace abyss
{
    class game {
        public:
            game();
            ~game() {};
            void run();

        private:
            sf::RenderWindow window;
            std::vector<level> levels;
            int lvl_id = 0;
            level current_level;
            Math::Vector camera;
            player actor;
            int side;
            char hitted;
            void ray_first_step(Math::Vector ray, Math::Vector &side_move, Math::Point offset, Math::Vector &steps);
            int dda_algorithm(Math::Vector &side_move, Math::Point offset, Math::Vector &steps);
            void render_line(int dist, int x);
            void render_handler();
            void update_handler();
            void event_handler();
    };
}