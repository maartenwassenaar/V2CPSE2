#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "box.hpp"
#include "drawable.hpp"
#include "Walls.hpp"

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

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball		{ sf::Vector2f{ 425, 245 },sf::Color::Red };
	box my_box			{ sf::Vector2f{5,5},sf::Color::Yellow,sf::Vector2f{30.0,30.0} };
	Walls my_wall_north	{ sf::Vector2f{ 0, 0 },		sf::Color::Green, sf::Vector2f{640.0,5.0 } };
	Walls my_wall_east	{ sf::Vector2f{ 635, 0 }, sf::Color::Green, sf::Vector2f{ 5.0,640.0 } };
	Walls my_wall_south	{ sf::Vector2f{ 0, 475 }, sf::Color::Green, sf::Vector2f{ 640.0,5.0 } };
	Walls my_wall_west	{ sf::Vector2f{ 0, 0 },		sf::Color::Green, sf::Vector2f{ 5.0,640.0 } };
	bool state = true;

	drawable * obj_walls[] = { &my_wall_north, &my_wall_east, &my_wall_south, &my_wall_west};

	action actions[] = {
		action( state,				 [&](){ my_ball.update(my_ball,my_box,my_wall_north,my_wall_east,my_wall_south,my_wall_west); }),
		action( sf::Keyboard::Left,  [&](){ my_box.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ my_box.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ my_box.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ my_box.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ my_box.jump( sf::Mouse::getPosition( window )); })
	};
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		window.clear();
		my_ball.draw( window );
		my_box.draw(window);
		my_wall_north.draw(window);
		my_wall_east.draw(window);
		my_wall_south.draw(window);
		my_wall_west.draw(window);
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

