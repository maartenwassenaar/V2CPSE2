#ifndef _WALLS_HPP
#define _WALLS_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class Walls : public drawable {
public:

	Walls(sf::Vector2f position, sf::Color color, sf::Vector2f size);

	void draw(sf::RenderWindow & window) override;
	sf::FloatRect get_bounding_box();
	sf::Vector2f get_size();

private:
	sf::Vector2f size;
	sf::RectangleShape rectangle;
};

#endif
