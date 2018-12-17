#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>


class line : public drawable {
private:
	sf::Color color;
	sf::VertexArray line_shape;

public:

	line(sf::Vector2f position, sf::Vector2f position2, sf::Color color);

	void draw(sf::RenderWindow & window) override;
	void select(sf::Vector2i target) override;
	std::string gettype() override;
	std::string getdata() override;

};

#endif
