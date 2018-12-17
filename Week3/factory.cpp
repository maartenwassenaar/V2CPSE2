#include "factory.hpp"

factory::factory(){

	create();	
	box *pbox = new box(sf::Vector2f(0, 0), sf::Vector2f(100, 100), sf::Color::Yellow);
	circle *pcircle = new circle(sf::Vector2f(0, 100), sf::Vector2f(100, 200), sf::Color::Green);
	line *pline = new line(sf::Vector2f(100, 50), sf::Vector2f(200, 50), sf::Color::Blue);
	add(pbox);
	add(pcircle);
	add(pline);
	picture *ppic = new picture(sf::Vector2f(100, 100), sf::Vector2f(200, 200), "afbeelding1.png");
	add(ppic);
}

factory::~factory(){
	std::ofstream objects_file;
	objects_file.open("object.txt");
	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it){
		if ((*it)->gettype() == "BOX") {
			objects_file << (*it) -> getdata() << "\n";
		}
		if ((*it)->gettype() == "CIRCLE") {
			objects_file << (*it)->getdata() << "\n";
		}
		if ((*it)->gettype() == "LINE") {
			objects_file << (*it)->getdata() << "\n";
		}
		if ((*it)->gettype() == "PICTURE") {
			objects_file << (*it)->getdata() << "\n";
		}
	}
	objects_file.close();
}

void factory::draw(sf::RenderWindow & window) {
	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it){
		(*it)->draw(window);
	}
}

void factory::select(sf::Vector2i target) {
	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it) {
		(*it)->select(target);
	}
}

void factory::move(sf::Vector2f delta){
	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it) {
		(*it)->move(delta);
	}
}

void factory::add(drawable* obj) {
	drawvec.push_back(obj);
}

void factory::create() {
	sf::Vector2f pos1, pos2;
	std::string type;
	std::string arg;

	try {
		std::ifstream object_file("object.txt");
		while (object_file >> pos1 >> pos2 >> type >> arg) {

			if (type == "BOX") {
				box *bp = new box(pos1,pos2, indentifycolor(arg));
				add(bp);
			}
			else if (type == "CIRCLE") {
				circle *cp = new circle(pos1,pos2, indentifycolor(arg));
				add(cp);
			}
			else if (type == "LINE") {
				line *lp = new line(pos1,pos2, indentifycolor(arg));
				add(lp);
			}
			else if (type == "PICTURE") {
				picture *pp = new picture(pos1,pos2, arg);
				add(pp);
			}
			else {
				throw unknown_name(type);
			}
		}
	}
	catch (end_of_file) {
		//do nothing
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
	}

}


sf::Color factory::indentifycolor(std::string colortemp) {
	const struct { const char * name; sf::Color color_list; } colors_list[]{
		{ "YELLOW", sf::Color::Yellow },
		{ "RED",    sf::Color::Red },
		{ "BLUE",	sf::Color::Blue },
		{ "GREEN",	sf::Color::Green }
	};
		for (auto const & c : colors_list) {
			if (c.name == colortemp) {
				return c.color_list;
			}
		}
		throw unknown_color(colortemp);
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }
	if (!(input >> rhs.x)) {}
	if (!(input >> c)) {}
	if (!(input >> rhs.y)) {}
	if (!(input >> c)) {}
	if (c != ')') { throw invalid_position(c); }

	return input;
}



