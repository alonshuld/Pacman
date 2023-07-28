#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "headers/Global.h"
#include "headers/ConvertSketch.h"
#include "headers/DrawMap.h"

int main()
{
	sf::Clock clock;
	float curr_time = 0;
	float last_time = 0;
	float lag = 0;

	std::array<std::string, MAP_HEIGHT> map_sketch = {
		" ################### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #                 # ",
		" # ## # ##### # ## # ",
		" #    #   #   #    # ",
		" #### ### # ### #### ",
		"    # #       # #    ",
		"##### # ## ## # #####",
		"        #   #        ",
		"##### # ##### # #####",
		"    # #       # #    ",
		" #### # ##### # #### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #  #     P     #  # ",
		" ## # # ##### # # ## ",
		" #    #   #   #    # ",
		" # ###### # ###### # ",
		" #                 # ",
		" ################### "
	};

	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

	sf::Event event;
	
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, CELL_SIZE * MAP_HEIGHT * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, CELL_SIZE * MAP_HEIGHT)));

	Pacman pacman;

	map = convert_sketch(map_sketch, pacman);

	while (window.isOpen())
	{
		curr_time = clock.getElapsedTime().asSeconds();
		
		if (FRAME_DURATION <= curr_time - last_time)
		{
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
			window.clear();
			draw_map(map, window);
			pacman.draw(window);
			pacman.update(map);
			window.display();
			last_time = curr_time;
		}
	}
}