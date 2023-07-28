#pragma once

#include <array>
#include "Global.h"

bool wall_collision(int i_x, int i_y, const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map);