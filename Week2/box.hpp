#ifndef _BOX_HPP
#define _BOX_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class box : public drawable {
private:
	sf::Vector2f size;
	sf::RectangleShape rectangle;
	sf::Vector2f movement;
public:

	box(sf::Vector2f position, sf::Color color, sf::Vector2f size );

	void draw(sf::RenderWindow & window) override;

	void move(sf::Vector2f delta);

	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

	sf::FloatRect get_bounding_box();

	sf::Vector2f get_size();


};

#endif
