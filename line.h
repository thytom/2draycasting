#ifndef LINE_H_
#define LINE_H_

#include <SFML/Graphics.hpp>

class Line
{
	public:
		Line(float x1, float y1, float x2, float y2);
		Line(sf::Vertex p1, sf::Vertex p2);
		void draw(sf::RenderWindow *window);
		sf::Vertex *getPoints();
	private:
		sf::Vertex points[2];
};

#endif
