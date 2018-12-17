#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include "box.hpp"
#include "drawable.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "factory.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work) :
		condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}
	action(
		bool state,
		std::function< void() > work
	) :
		condition(
			[state]()->bool { return (state); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};


int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";
	
	factory fac;
	
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	action actions[] = {
		action(sf::Mouse::Left,     [&]() { fac.select(sf::Mouse::getPosition(window)); }),
		action(sf::Keyboard::Left, [&]() { fac.move(sf::Vector2f(-1.0, 0.0)); }),
		action(sf::Keyboard::Right, [&]() { fac.move(sf::Vector2f(+1.0, 0.0)); }),
		action(sf::Keyboard::Up, [&]() { fac.move(sf::Vector2f(0.0, -1.0)); }),
		action(sf::Keyboard::Down, [&]() { fac.move(sf::Vector2f(0.0, +1.0)); }) 
	};
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		window.clear();
		fac.draw(window);
		window.display();

		sf::sleep( sf::milliseconds( 20 ));


        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}
