#include "particle.h"

Particle::Particle(sf::Vector2f pos, int num_rays)
{
	this->pos = pos;

	for(int i = 0; i < num_rays; i++)
	{
		rays.push_back(new Ray(pos, (360.0/num_rays) * i));
	}
}

void Particle::move(sf::Vector2f pos)
{
	this->pos = pos;
	for(size_t i = 0; i < rays.size(); i++) // For each ray
		rays[i]->pos = pos;
}

void Particle::scatter(sf::RenderWindow *rw, std::vector<Line*> walls)
{
	scatter(rw, walls, NULL);
}

// Shader Version
void Particle::scatter(sf::RenderWindow *rw,
		std::vector<Line*> walls, sf::Shader *s)
{
	for(size_t i = 0; i < rays.size(); i++) // For each ray
	{
		auto r = rays[i];
		sf::Vertex *closest = NULL;
		for(size_t j = 0; j < walls.size(); j++) // Loop over each wall
		{
			auto wall = walls[j];
			auto maybe = r->cast(*wall);
			if(maybe && ((closest == NULL)
						|| (distance(*maybe, sf::Vertex(r->pos))
							< distance(*closest, sf::Vertex(r->pos))))
			  )
			{
				closest = maybe;
			}
		}
		if(closest)
		{
			sf::Vertex l[] = {
				sf::Vertex(r->pos),
				*closest
			};
			rw->draw(l, 2, sf::Lines);
		}
	}
}

float Particle::distance(sf::Vertex p1, sf::Vertex p2)
{
	float x1 = p1.position.x;
	float y1 = p1.position.y;
	float x2 = p2.position.x;
	float y2 = p2.position.y;

	float a = (y1 - y2) * (y1 - y2);
	float b = (x1 - x2) * (x1 - x2);

	float distance = sqrt(a + b);

	return distance;
}
