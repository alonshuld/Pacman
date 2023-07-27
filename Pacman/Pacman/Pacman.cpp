#include "headers/Pacman.h"

void Pacman::draw(sf::RenderWindow& i_window)
{
	sf::CircleShape circle(CELL_SIZE / 2);
	circle.setFillColor(sf::Color(255, 255, 0));
	circle.setPosition(pos.x, pos.y);

	i_window.draw(circle);
}

void Pacman::set_position(int i_x, int i_y)
{
	pos = { i_x, i_y };
}
