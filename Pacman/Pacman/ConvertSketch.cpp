#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "headers/Global.h"
#include "headers/ConvertSketch.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convert_sketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch)
{
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};

    for (unsigned int i = 0; i < MAP_HEIGHT; i++)
    {
        for (unsigned int j = 0; j < MAP_WIDTH; j++)
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
            }
        }
    }
    return output_map;
}
