#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>


class circle : public drawable {
private:
	sf::Color color;
	sf::CircleShape circle_shape;
public:

	circle(sf::Vector2f position, sf::Vector2f position2, sf::Color color);

	void draw(sf::RenderWindow & window) override;
	void circle::select(sf::Vector2i target) override;
	std::string gettype() override;
	std::string getdata() override;


};

#endif
