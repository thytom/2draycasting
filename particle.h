#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "main.h"
class Ray;

class Particle // Emits rays all around it
{
	public:
		Particle(sf::Vector2f pos, int num_rays);
		void scatter(sf::RenderWindow *rw, std::vector<Line*> walls);
		void move(sf::Vector2f pos);
		sf::Vector2f pos;
		std::vector<Ray*> rays;
	private:
		float distance(sf::Vertex p1, sf::Vertex p2);

};

#endif
