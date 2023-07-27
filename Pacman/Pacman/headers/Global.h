#pragma once

const unsigned int CELL_SIZE = 16;
const unsigned int MAP_HEIGHT = 21;
const unsigned int MAP_WIDTH = 21;
const unsigned int SCREEN_RESIZE = 2;
const unsigned int FRAME_DURATION = 16667;

enum Cell
{
	Empty,
	Wall
};

struct Position
{
	short x;
	short y;

	bool operator==(const Position& i_position)
	{
		return this->x == i_position.x && this->y == i_position.y;
	}
};