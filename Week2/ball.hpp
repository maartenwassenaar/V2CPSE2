#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>


class ball : public drawable {
public:

	ball(sf::Vector2f position, sf::Color color, float size = 30);

	void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );

	void update(drawable & ball, drawable & box, drawable & north, drawable & east, drawable & south, drawable & west);
	sf::FloatRect get_bounding_box();

	sf::Vector2f get_size();

private:
	float size;
	sf::CircleShape circle;
	sf::Vector2f movement;
	sf::Color Color;
};

#endif
