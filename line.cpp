#include "line.h"

Line::Line(float x1, float y1, float x2, float y2)
{
	this->points[0] = sf::Vertex(sf::Vector2f(x1, y1));
	this->points[1] = sf::Vertex(sf::Vector2f(x2, y2));
}

Line::Line(sf::Vertex p1, sf::Vertex p2)
{
	this->points[0] = p1;
	this->points[1] = p2;
}

sf::Vertex *Line::getPoints(){
	return points;
}

void Line::draw(sf::RenderWindow *window)
{
	window->draw(points, 2, sf::Lines);
}
