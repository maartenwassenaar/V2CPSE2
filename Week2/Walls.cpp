#include <SFML/Graphics.hpp>
#include "walls.hpp"

Walls::Walls(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
	drawable(position,color),
	size{ size }
{}

void Walls::draw(sf::RenderWindow & window) {
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

sf::FloatRect Walls::get_bounding_box() {
	return rectangle.getGlobalBounds();
}

sf::Vector2f Walls::get_size() {
	return size;
}
