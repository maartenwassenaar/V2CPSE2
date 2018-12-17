#include <SFML/Graphics.hpp>
#include "box.hpp"

box::box(sf::Vector2f position, sf::Vector2f position2, sf::Color color) :
	drawable(position,position2),
	color( color )
{
	rectangle.setPosition(position);
	rectangle.setSize(position2-position);
	rectangle.setFillColor(color);
}

void box::draw(sf::RenderWindow & window) {
	rectangle.setPosition(position);
	rectangle.setSize((position2 - position));
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

void box::select(sf::Vector2i target) {
	sf::Vector2f target2(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	);
	if (rectangle.getGlobalBounds().contains(target2.x, target2.y)) {
		selected = true;
	}
	else {
		selected = false;
	}
}

std::string box::gettype() {
	return "BOX";
}

std::string box::getdata() {
	return(getpos1() + " " + getpos2() + " " + gettype() + " " + getcolor_string(color));
}