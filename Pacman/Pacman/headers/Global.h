#pragma once

const int CELL_SIZE = 16;
const int MAP_HEIGHT = 21;
const int MAP_WIDTH = 21;
const int SCREEN_RESIZE = 2;
const int PACMAN_SPEED = 2;
const float FRAME_DURATION = 1.0f / 60.0f;

enum Cell
{
	Empty,
	Wall,
	Pellet
};

struct Position
{
	int x;
	int y;

	bool operator==(const Position& i_position)
	{
		return this->x == i_position.x && this->y == i_position.y;
	}
};