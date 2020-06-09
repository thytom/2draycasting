#include "ray.h"

Ray::Ray()
{
	this->pos = sf::Vector2f(0, 0);
	this->setAngle(0);
}

Ray::Ray(sf::Vector2f pos, float angle)
{
	this->pos = pos;
	this->setAngle(angle);
}

sf::Vertex* Ray::cast(Line w)
{
	float x1 = w.getPoints()[0].position.x;
	float y1 = w.getPoints()[0].position.y;
	float x2 = w.getPoints()[1].position.x;
	float y2 = w.getPoints()[1].position.y;

	float x3 = this->pos.x;
	float y3 = this->pos.y;
	float x4 = this->pos.x + this->dir.x;
	float y4 = this->pos.y + this->dir.y;

	float d =  (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	if(d == 0)
		return NULL;

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4))/d;
	float u = ((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3))/d;

	if(u >= 0 || ((t < 0) || t >= 1))
		return NULL;

	return new sf::Vertex(sf::Vector2f(x1 + t*(x2 - x1), y1 + t*(y2-y1)));
}

void Ray::draw(sf::RenderWindow *rw)
{
	sf::Vertex l[] = {
		sf::Vertex(pos),
		sf::Vertex(pos + (sf::Vector2f(dir.x * 20, dir.y * 20)))
	};

	rw->draw(l, 2, sf::Lines);
}

void Ray::setAngle(float angle)
{
	this->angle = angle;
	sf::Transform t;
	t.rotate(angle);
	dir = t.transformPoint(sf::Vector2f(1, 0));
}

void Ray::rotate(float angle)
{
	this->angle += angle;
	sf::Transform t;
	t.rotate(angle);
	dir = t.transformPoint(dir);
}
