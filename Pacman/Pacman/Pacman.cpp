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

void Pacman::update(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map)
{
	std::array<bool, 4> walls{};
	walls[0] = wall_collision(pos.x + PACMAN_SPEED, pos.y, i_map);
	walls[1] = wall_collision(pos.x, pos.y - PACMAN_SPEED, i_map);
	walls[2] = wall_collision(pos.x - PACMAN_SPEED, pos.y, i_map);
	walls[3] = wall_collision(pos.x, pos.y + PACMAN_SPEED, i_map);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		direction = 0;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		direction = 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction = 2;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		direction = 3;

	switch (direction)
	{
		case 0:
		{
			if(!walls[0])
				pos.x += PACMAN_SPEED;
			break;
		}
		case 1:
		{
			if (!walls[1])
				pos.y -= PACMAN_SPEED;
			break;
		}
		case 2:
		{
			if (!walls[2])
				pos.x -= PACMAN_SPEED;
			break;
		}
		case 3:
		{
			if (!walls[3])
				pos.y += PACMAN_SPEED;
			break;
		}
	}
	
}
