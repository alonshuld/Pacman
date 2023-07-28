#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "WallCollision.h"
#include "Global.h"

class Pacman
{
private:
	int direction = 0;
	Position pos;
public:
	void draw(sf::RenderWindow& i_window);
	void set_position(int i_x, int i_y);
	void update(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map);
};