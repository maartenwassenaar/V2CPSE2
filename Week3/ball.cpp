#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>

ball::ball( sf::Vector2f position, sf::Color color, float size):
	drawable(position,color),
	size(size)
{
}

void ball::draw( sf::RenderWindow & window){
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

sf::FloatRect ball::get_bounding_box() {
	return circle.getGlobalBounds();
}

sf::Vector2f ball::get_size(){
	return sf::Vector2f{ size,0 };
}