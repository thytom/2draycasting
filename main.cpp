#include "main.h"
#include <random>
#include <functional>
#include <chrono>

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML Raytracing Demo");
	std::default_random_engine rng;
	std::uniform_int_distribution<int> distribution(0, 700);
	unsigned time = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		).count();
	rng.seed(time);

	std::vector<Line*> walls;
	walls.push_back(new Line(0, 0, 0, 700));
	walls.push_back(new Line(0, 0, 700, 0));
	walls.push_back(new Line(700, 700, 0, 700)); // Left
	walls.push_back(new Line(700, 700, 700, 0)); // Left

	auto rand = std::bind(distribution, rng);

	walls.push_back(new Line(rand(), rand(), rand(), rand()));
	walls.push_back(new Line(rand(), rand(), rand(), rand()));
	walls.push_back(new Line(rand(), rand(), rand(), rand()));
	walls.push_back(new Line(rand(), rand(), rand(), rand()));
	walls.push_back(new Line(rand(), rand(), rand(), rand()));
	walls.push_back(new Line(rand(), rand(), rand(), rand()));


	Particle p(sf::Vector2f(200, 200), 360);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}


		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		p.move(mousePos);

		window.clear();
		for(size_t i = 0; i < walls.size(); i++)
		{
			walls[i]->draw(&window);
		}
		p.scatter(&window, walls);
		sf::sleep(sf::milliseconds(1000 / 120));
		window.display();
	}

	return 0;
}
