/*
** EPITECH PROJECT, 2024
** cpp project
** File description:
** MyTek 2 project
*/

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <sfml_ui.hpp>
#include <iostream>
#include "../include/core.hpp"

abyss::game::game() : window(sf::VideoMode(1900, 1000), "Mars-abyss") {
    std::filesystem::path lvl_file("./assets/levels");
    for (const auto &it : std::filesystem::directory_iterator(lvl_file)) {
        levels.push_back(abyss::level(it.path()));
    }
    std::sort(levels.begin(), levels.end());
    actor.name("Anonymous");
    actor.position(levels[0].player_pos());
    camera.x = 0;
    camera.y = 0.66;
}

void abyss::game::ray_first_step(Math::Vector ray, Math::Vector &side_move,
    Math::Point offset, Math::Vector &steps)
{
    Math::Point pos = actor.position();
    int mapx = int(pos.x);
    int mapy = int(pos.y);

    if (ray.x < 0) {
        steps.x = -1;
        side_move.x = (pos.x - mapx) * offset.x;
    } else {
        steps.x = 1;
        side_move.x = (mapx + 1 - pos.x);
    }
    if (ray.y < 0) {
        steps.y = -1;
        side_move.y = (pos.y - mapy) * offset.y;
    } else {
        steps.y = 1;
        side_move.y = (mapy + 1 - pos.y);
    }
}

int abyss::game::dda_algorithm(Math::Vector &side_move, Math::Point offset,
    Math::Vector &steps)
{
    Math::Point pos = actor.position();
    std::vector<std::string> map = levels[0].map();
    int mapx = int(pos.x);
    int mapy = int(pos.y);
    int hit = 0;
    int dist = 1;

    while (hit == 0) {
        if (side_move.x < side_move.y) {
            side_move.x += offset.x;
            mapx += steps.x;
            side = 0;
        } else {
            side_move.y += offset.y;
            mapy += steps.y;
            side = 1;
        }
        if (map[mapy][mapx] != ' ') hit = 1;
    }
    hitted = map[mapy][mapx];
    if (side == 0) dist = (side_move.x - offset.x);
    else dist = (side_move.y - offset.y);
    return dist;
}

void abyss::game::render_line(int dist, int x)
{
    if (dist == 0)
        dist = 1;
    int line_height = (int) 1000 / dist;
    int a = -line_height / 2 + 500;
    int b = line_height / 2 + 500;
    if (a < 0)
        a = 0;
    if (b < 0)
        b = 999;
    sf::Vector2f start(x, a);
    sf::Vector2f end(x, b);
    sf::VertexArray array(sf::Lines, 2);
    sf::Color col;
    switch (hitted) {
    case '@': col = sf::Color(120, 10, 20);
        break;
    case '*': col = sf::Color(0, 0, 255);
        break;
    case '#': col = sf::Color(0, 0, 255);
        break;
    default: col = sf::Color(255, 0, 0);
        break;
    }
    if (side == 1) {
        col.r /= 2;
        col.g /= 2;
        col.b /= 2;
    }
    if (hitted == '@')
        std::cout << "rhe\n";
    array.append(sf::Vertex(start, col));
    array.append(sf::Vertex(end, col));
    window.draw(array);
}

void abyss::game::render_handler()
{
    window.clear(sf::Color::Black);
    for (int x = 0; x < 1900; x++) {
        double coef = 2 * x / 1900.0 - 1;
        int dist = 0;
        Math::Vector side_move;
        Math::Vector steps;
        Math::Vector dir = actor.direction();
        Math::Point pos = actor.position();
        Math::Vector ray(dir.x + (camera.x * coef), dir.y + (camera.y * coef));
        Math::Point offset(std::abs(1 / ray.x), std::abs(1 / ray.y));

        ray_first_step(ray, side_move, offset, steps);
        dist = dda_algorithm(side_move, offset, steps);
        render_line(dist, x);
    }
    window.display();
}

void abyss::game::event_handler()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void abyss::game::update_handler()
{
    
}

void abyss::game::run()
{
    while (window.isOpen()) {
        render_handler();
        event_handler();
        update_handler();
    }
}
