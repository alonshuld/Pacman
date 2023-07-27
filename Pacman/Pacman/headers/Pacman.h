#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"

class Pacman
{
private:
	Position pos;
public:
	void draw(sf::RenderWindow& i_window);
	void set_position(int i_x, int i_y);
};