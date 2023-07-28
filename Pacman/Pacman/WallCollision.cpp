#include "headers/WallCollision.h"

bool wall_collision(int i_x, int i_y, const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map)
{
    std::array<Cell, 4> cells{};

    cells[0] = i_map[floor(i_x / static_cast<float>(CELL_SIZE))][floor(i_y / static_cast<float>(CELL_SIZE))];
    cells[1] = i_map[ceil(i_x / static_cast<float>(CELL_SIZE))][floor(i_y / static_cast<float>(CELL_SIZE))];
    cells[2] = i_map[floor(i_x / static_cast<float>(CELL_SIZE))][ceil(i_y / static_cast<float>(CELL_SIZE))];
    cells[3] = i_map[ceil(i_x / static_cast<float>(CELL_SIZE))][ceil(i_y / static_cast<float>(CELL_SIZE))];

    for (Cell& cell : cells)
        if (cell == Cell::Wall)
            return true;

    return false;
}
