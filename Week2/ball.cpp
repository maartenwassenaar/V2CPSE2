#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>

ball::ball( sf::Vector2f position, sf::Color color, float size):
	drawable(position,color),
	size(size)
{
	movement = sf::Vector2f(1.0, 1.0);
}

void ball::draw( sf::RenderWindow & window){
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	position += delta;
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

void ball::update(drawable & ball, drawable & box, drawable & north, drawable & east, drawable & south, drawable & west) {

	if(intersect(ball, box)){
		if (ball.get_position().y - (box.get_position().y + box.get_size().y) == -1) {
			//std::cout << "north";
			movement = { movement.x * 1 ,movement.y * -1 };
		}
		if ((ball.get_position().y + (size*2)) - (box.get_position().y) == 1) {
			//std::cout << "south";
			movement = { movement.x * 1 ,movement.y * -1 };
		}
		if ((ball.get_position().x - (box.get_position().x + box.get_size().x) == -1)) {
			//std::cout << "west";
			movement = { movement.x * -1 ,movement.y * 1 };
		}
		if ((ball.get_position().x + (size * 2)) - (box.get_position().x) == 1) {
			//std::cout << "east";
			movement = { movement.x * -1 ,movement.y * 1 };
		}
		
	}

	if(intersect(ball, north)){
		movement = { movement.x * 1,movement.y * -1 };
	}
	if(intersect(ball, east)){
		movement = { movement.x * -1,movement.y * 1 };
	}
	if(intersect(ball, south)){
		movement = { movement.x * 1,movement.y * -1 };
	}
	if(intersect(ball, west)){
		movement = { movement.x * -1,movement.y * 1 };
	}
	move(movement);
}

sf::FloatRect ball::get_bounding_box() {
	return circle.getGlobalBounds();
}

sf::Vector2f ball::get_size(){
	return sf::Vector2f{ size,0 };
}