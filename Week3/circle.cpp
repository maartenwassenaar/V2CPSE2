#include <SFML/Graphics.hpp>
#include "circle.hpp"

circle::circle(sf::Vector2f position, sf::Vector2f position2, sf::Color color) :
	drawable(position, position2),
	color(color)
{
	if ((position2.x - position.x) != (position2.y - position.y)){
		std::cout << "Error: circle cant be oval";
		position2.x = position2.y;
	}
}

void circle::draw(sf::RenderWindow & window) {
	circle_shape.setPosition(position);
	circle_shape.setRadius((position2.x-position.x)/2);
	circle_shape.setFillColor(color);
	window.draw(circle_shape);
}

void circle::select(sf::Vector2i target) {
	sf::Vector2f target2(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	);
	if (circle_shape.getGlobalBounds().contains(target2.x, target2.y)) {
		selected = true;
	}
	else {
		selected = false;
	}
}

std::string circle::gettype() {
	return "CIRCLE";
}

std::string circle::getdata() {
	return(getpos1() + " " + getpos2() + " " + gettype() + " " + getcolor_string(color));
}