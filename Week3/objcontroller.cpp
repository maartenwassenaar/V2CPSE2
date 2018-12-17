//#include "objcontroller.hpp"
//
//objcontroller::objcontroller()
//{
//	box *pbox = new box(sf::Vector2f(0, 0), sf::Vector2f(100, 100), sf::Color::Yellow);
//	circle *pcircle = new circle(sf::Vector2f(0, 100), sf::Vector2f(100, 100), sf::Color::Green);
//	line *pline = new line(sf::Vector2f(100, 50), sf::Vector2f(200, 50), sf::Color::Blue);
//	add(pbox);
//	add(pcircle);
//	add(pline);
//}
//
//objcontroller::~objcontroller()
//{
//	std::ofstream objects_file;
//	objects_file.open("object.txt");
//	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it)
//	{
//		objects_file << (*it)->gettype() << " " << (*it)->getpos1() << " " << (*it)->getpos2() << " " << (*it)->getcolor_string(sf::Color::Red) << "\n";
//	}
//	objects_file.close();
//}
//
//void objcontroller::draw(sf::RenderWindow & window) {
//	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it)
//	{
//		(*it)->draw(window);
//	}
//}
//
//void objcontroller::add(drawable* obj) {
//	drawvec.push_back(obj);
//}
//
//void objcontroller::gettype() {
//	for (std::vector<drawable*>::iterator it = drawvec.begin(); it != drawvec.end(); ++it)
//	{
//		std::cout<< (*it)->gettype();
//	}
//}