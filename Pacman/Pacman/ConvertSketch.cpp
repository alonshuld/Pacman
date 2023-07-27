#include "headers/ConvertSketch.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convert_sketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, Pacman& i_pacman)
{
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};

    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            switch (i_map_sketch[i][j])
            {
                case ' ':
                {
                    output_map[j][i] = Cell::Empty;
                    break;
                }
                case '#':
                {
                    output_map[j][i] = Cell::Wall;
                    break;
                }
                case 'P':
                {
                    i_pacman.set_position(CELL_SIZE * j, CELL_SIZE * i);
                }
            }
        }
    }
    return output_map;
}
