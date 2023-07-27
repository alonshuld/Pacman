#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "headers/Global.h"
#include "headers/ConvertSketch.h"
#include "headers/DrawMap.h"

int main()
{
	unsigned lag = 0;
	unsigned delta_time = 0;

	std::chrono::time_point<std::chrono::steady_clock> previous_time;

	std::array<std::string, MAP_HEIGHT> map_sketch = {
		"#####################",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#     #       #     #",
		"#                   #",
		"#         #         #",
		"#                   #",
		"#   #           #   #",
		"#    ###########    #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#####################"
	};

	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

	sf::Event event;
	
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, CELL_SIZE * MAP_HEIGHT * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, CELL_SIZE * MAP_HEIGHT)));

	map = convert_sketch(map_sketch);

	previous_time = std::chrono::steady_clock::now();

	while (window.isOpen())
	{
		unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();

		lag += delta_time;

		previous_time += std::chrono::milliseconds(delta_time);

		while (FRAME_DURATION <= lag)
		{
			lag -= FRAME_DURATION;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						window.close();
					}
				}
			}

			if (FRAME_DURATION > lag)
			{
				window.clear();
				draw_map(map, window);
				window.display();
			}
		}
	}
}