#include "picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f position2, std::string filepath) :
	drawable(position, position2),
	filepath(filepath)
{
	if (!texture.loadFromFile(filepath))
		std::cout << "ERROR: unable to load texture\n";
	const sf::Texture *pt = &texture;
	rectangle.setPosition(position);
	rectangle.setSize((position2 - position));
	rectangle.setTexture(pt);
}

void picture::draw(sf::RenderWindow & window) {
	rectangle.setPosition(position);
	rectangle.setSize((position2 - position));
	window.draw(rectangle);
}

void picture::select(sf::Vector2i target) {
	sf::Vector2f target2(
		static_cast<float>(target.x),
		static_cast<float>(target.y)
	);
	if (rectangle.getGlobalBounds().contains(target2.x, target2.y)) {
		selected = true;
	}
	else {
		selected = false;
	}
}

std::string picture::gettype() {
	return "PICTURE";
}

std::string picture::getdata() {
	return(getpos1() + " " + getpos2() + " " + gettype() + " " + filepath);
}