#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class drawable {
protected:
	sf::Vector2f position;
	sf::Vector2f position2;
	bool selected = false;
public:
	drawable(sf::Vector2f position, sf::Vector2f position2);

	std::string getpos1();
	std::string getpos2();
	void move(sf::Vector2f delta);
	std::string getcolor_string(sf::Color color);



	virtual void draw( sf::RenderWindow & window ) = 0;
	virtual void select(sf::Vector2i target) = 0;
	virtual std::string gettype() =0;
	virtual std::string getdata() =0;

};
	
#endif
