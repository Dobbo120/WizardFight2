#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Background.h"

#include "Wizard.h"

using namespace sf;

int main()
{
	//Rendering the window, VideoMode.getFullscreenModes returns an array of the fullscreen options with the "best" first
	VideoMode vm;
	RenderWindow window(vm.getFullscreenModes()[0], "WizardFight2");

	//Seeding the random Generator
	srand((int)time(0));
		
	
	
	//This creates the position for the wizard, to have it centered, I grab the pixel size of the wizard multiplied by the game scale and half it to offset.
	//Is this potentially off by a pixel?  (Based on theory not observation)
	int windowWidth = window.getSize().x;
	int windowHeight = window.getSize().y;

	float gameScale = 3;
	//Scaling the game makes it easier for me to see everything on my monitor, eventually it would be nice to scale this dynamically with detected monitor size, and/or implement a slider for
	//players to choose their preference
	


	Wizard wizard(windowWidth , windowHeight , gameScale);

	Background background;

	if (!background.load("graphics/GrassTiles.png", { 32,32 }, gameScale)) {
		return -1;
	}


	Clock clock;
	clock.start();
	//Clock initiated for handling movement, but there is no movement yet

	bool moveL = false;
	bool moveR = false;
	bool moveU = false;
	bool moveD = false;


	while (window.isOpen()) {

		//optional can either hold a value or be empty, so in this case, I suppose it's whether or not there is an event from the window, it surprises me that this is a subloop
		//it seems like it could just be an if statement, but maybe this works better with timing, i.e. you can hold down the x button otherwise lag from elsewhere in the loop might make
		//magical moments where you could click without the event being caught.  ...maybe.  Actually, it's probably for multiple event handling ...maybe
		while (const std::optional event = window.pollEvent())
		{
			//This is taken from the SFML Tutorial on their website
			if (event->is<Event::Closed>()) {
				window.close();
			}
			
		}
        // update
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			std::cout << "Hi";
			//So everything does move, I wanted this in a separate cpp, but I didn't have a great idea of the implementation.  Obviously, everything moves at tick rate and only diagonally.
			//I may also mess with the implementation here because I need to handle diagonal fast movement.  Right now I am probably planning to put the directions into enums(?)
			//The next important thing that I will have to do is a check that when the x or y of the tiles are exceeded in a certain direction, I add new tiles to the edges and unload the tiles at the other edges
			//After that, I'm hoping to make a simple bin file to store binary data so that tiles aren't re-randomized every time
			background.move(1, {32, 32}, gameScale);
		}
		

		//draw

		window.clear();
				
		window.draw(background);

		window.draw(wizard.getSprite());


		clock.reset();
		

		window.display();
		
	}

	
}