#include <SFML/Graphics.hpp>
#include "drawable.hpp"

drawable::drawable(sf::Vector2f position, sf::Color color) :
	position(position),
	color(color)
{}

bool drawable::intersect(drawable &ball, drawable & rectangle){
	return ball.get_bounding_box().intersects(rectangle.get_bounding_box());
}

sf::Vector2f drawable::get_position() {
	return(position);
}


sf::Vector2f drawable::get_center_position(drawable & rectangle) {
	sf::Vector2f temp = { (rectangle.get_size().x) /2, (rectangle.get_size().y)/2 };
	return(rectangle.get_position() + temp);
}


