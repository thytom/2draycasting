#ifndef RAY_H_
#define RAY_H_

#include "main.h"

class Ray {
	public:
		Ray();
		Ray(sf::Vector2f pos, float angle);
		// Ray(float x1, float y1, float angle);
		sf::Vertex *cast(Line w);
		void draw(sf::RenderWindow *rw);
		void setAngle(float angle); // Resets angle to this angle
		void rotate(float angle); // Adds more rotation to current rotation
		sf::Vector2f pos;
	private:
		sf::Vector2f dir;
		float angle;
};

#endif
