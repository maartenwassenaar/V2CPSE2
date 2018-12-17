#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"
#include "box.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "picture.hpp"
#include <vector>
#include <fstream>
#include <exception>
#include "exeption.hpp"

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs);

class factory {
protected:
	std::vector<drawable*> drawvec;
public:
	factory();
	~factory();
	void draw(sf::RenderWindow & window);
	void select(sf::Vector2i);
	void add(drawable* obj);
	void create();
	void move(sf::Vector2f delta);
	sf::Color indentifycolor(std::string colortemp);
};

#endif