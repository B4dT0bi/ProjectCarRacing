#include "game.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

#include "OpenFileError.hpp"


void getEvents(sf::RenderWindow &window)
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				exit(EXIT_SUCCESS);
				break;
			case sf::Event::KeyPressed:
				break;
			case sf::Event::KeyReleased:
				break;
			default:
				break;
		}
	}

}


void game(sf::RenderWindow &window)
{
	//image loading
	std::vector<Car> carsTab;
	loadCars(carsTab);

	//sound loading
	
	//music loading

	

	//other variables

	//main loop
	while(true)
	{
		//getEvents(window);

		//game physic/////////////////////////////
		
		//moving cars
		//

		// \game physics /////////////////////////

		std::cout<< "boucle\n";

		
		window.clear(sf::Color::Black);
		//game display
		window.draw(carsTab[0]);

		window.display();
	}

}


void loadCars(std::vector<Car> &carsTab)
{
	try
	{
		sf::Texture texCar;
		if(!texCar.loadFromFile(CAR_FILE))
		{
			OpenFileError error;
			throw error;
		}

		carsTab.push_back(Car(texCar, CAR_SPEED, CAR_ACCELERATION));
	}
	catch(std::exception &except)
	{
		std::cerr<< except.what()<< "\n";
	}
}
