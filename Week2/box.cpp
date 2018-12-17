#include <SFML/Graphics.hpp>
#include "box.hpp"

box::box(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
	drawable(position,color),
	size( size )
{
	movement = sf::Vector2f(1.0, 1.0);
}

void box::draw(sf::RenderWindow & window) {
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

void box::move(sf::Vector2f delta) {
	position += delta;
}

void box::jump(sf::Vector2f target) {
	position = target;
}

void box::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
		static_cast< float >(target.x),
		static_cast< float >(target.y)
	));
}

sf::FloatRect box::get_bounding_box() {
	return rectangle.getGlobalBounds();
}

sf::Vector2f box::get_size() {
	return size;
}

