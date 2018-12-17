#ifndef _BOX_HPP
#define _BOX_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class box : public drawable {
private:
	sf::Color color;
	sf::RectangleShape rectangle;
public:

	box(sf::Vector2f position, sf::Vector2f position2, sf::Color color );

	void draw(sf::RenderWindow & window) override;
	void select(sf::Vector2i target) override;
	std::string gettype() override;
	std::string getdata() override;

};

#endif
