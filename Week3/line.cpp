#include <SFML/Graphics.hpp>
#include "line.hpp"

line::line(sf::Vector2f position, sf::Vector2f position2, sf::Color color) :
	drawable(position, position2),
	color(color)
{
	line_shape.setPrimitiveType(sf::PrimitiveType(sf::PrimitiveType::LinesStrip));
	line_shape.append(sf::Vertex(sf::Vector2f(position),sf::Color(color)));
	line_shape.append(sf::Vertex(sf::Vector2f(position2), sf::Color(color)));
}

void line::draw(sf::RenderWindow & window) {
	line_shape[0].position = position;
	line_shape[1].position = position2;
	line_shape[0].color = color;
	line_shape[1].color = color;
	window.draw(line_shape);
}

void line::select(sf::Vector2i target) {
	sf::Vector2f target2(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	);
	if (line_shape.getBounds().contains(target2.x, target2.y)) {
		selected = true;
	}
	else {
		selected = false;
	}
}

std::string line::gettype() {
	return "LINE";
}

std::string line::getdata() {
	return(getpos1() + " " + getpos2() + " " + gettype() + " " + getcolor_string(color));
}