#pragma once

#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "Pacman.h"
#include "headers/Global.h"

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convert_sketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, Pacman& i_pacman);