#include <SFML/Graphics.hpp>
#include "drawable.hpp"

drawable::drawable(sf::Vector2f position, sf::Vector2f position2) :
	position(position),
	position2(position2)
{}

std::string drawable::getpos1() {
	std::string tempstring = "(" + std::to_string(static_cast<int>(position.x)) + "," + std::to_string(static_cast<int>(position.y)) + ")";
	return tempstring;
}

std::string drawable::getpos2() {
	std::string tempstring2 = "(" + std::to_string( static_cast<int>(position2.x)) + "," + std::to_string(static_cast<int>(position2.y)) + ")" ;
	return tempstring2;
}

void drawable::move(sf::Vector2f delta) {
	if (selected == true) {
		position += delta;
		position2 += delta;
		//std::cout << gettype() << " : " << getpos1() << std::endl;
	}
}

std::string drawable::getcolor_string(sf::Color color) {
	if (color == sf::Color::Red) {
		return "RED";
	}
	if (color == sf::Color::Yellow) {
		return "YELLOW";
	}
	if (color == sf::Color::Blue) {
		return "BLUE";
	}
	if (color == sf::Color::Green) {
		return "GREEN";
	}
	return "ERROR_IN_GETTING_COLOR";
	
	//std::list<sf::Color> all_colors = { sf::Color::Black,sf::Color::Blue,sf::Color::Cyan,sf::Color::Green,sf::Color::Magenta,sf::Color::Red,sf::Color::White,sf::Color::Yellow };
	//std::list<std::string> all_colors_strings = { "Black","Blue","Cyan","Green","Magenta","Red","White","Yellow" };

	//std::map<int, std::string, sf::Color> all_colors;
	//all_colors[1] = sf::Color::Black;
	//for(sf::Color v : all_colors){
	//	if (color == v) {
	//		return all_colors_strings[v];
	//	}
	//}
}
