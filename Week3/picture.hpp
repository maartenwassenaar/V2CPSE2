#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>



class picture : public drawable {
private:
	std::string filepath;	
	sf::Texture texture;
	sf::RectangleShape rectangle;
public:

	picture(sf::Vector2f position, sf::Vector2f position2, std::string filepath);

	void draw(sf::RenderWindow & window) override;
	void select(sf::Vector2i target) override;
	std::string gettype() override;
	std::string getdata() override;

};

#endif
