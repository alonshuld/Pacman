#pragma once

#include <array>
#include <SFML/Graphics.hpp>

#include "headers/Global.h"

void draw_map(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, sf::RenderWindow& i_window);