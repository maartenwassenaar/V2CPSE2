#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:
	drawable(sf::Vector2f position, sf::Color color = sf::Color::White);
	virtual void draw( sf::RenderWindow & window ) = 0;
	virtual sf::FloatRect get_bounding_box() =0;
	virtual sf::Vector2f get_size() = 0;

	bool intersect(drawable &ball, drawable & rectangle);
	sf::Vector2f get_position();
	sf::Vector2f get_center_position(drawable & rectangle);
protected:
	sf::Vector2f position;
	sf::Color color;
};
	
#endif
