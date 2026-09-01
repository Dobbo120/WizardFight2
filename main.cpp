#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "BackgroundManager.h"
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

	BackgroundManager backgroundManager = BackgroundManager();

	//This seems so pointless to me, but debug throws a hissy fit if it's not a wide string
	//I think I know a better way to do this, but this whole code is likely to be changed with the implementation of the new Texture Management system.
	String grassTilePath = "graphics/GrassTiles.png";
	std::wstring grassTilePathW = grassTilePath.toWideString();

	backgroundManager.generate(windowWidth, windowHeight, gameScale, grassTilePathW);

	Clock clock;
	clock.start();
	//Clock initiated for handling movement, but there is no movement yet

	while (window.isOpen()) {

		//optional can either hold a value or be empty, so in this case, I suppose it's whether or not there is an event from the window, it surprises me that this is a subloop
		//it seems like it could just be an if statement, but maybe this works better with timing, i.e. you can hold down the x button otherwise lag from elsewhere in the loop might make
		//magical moments where you could click without the event being caught.  ...maybe
		while (const std::optional event = window.pollEvent())
		{
			//This is taken from the SFML Tutorial on their website
			if (event->is<Event::Closed>())
				window.close();
		}

		window.clear();
		
		//This system may effectively draw the background, but it is not the most memory efficient, especially with the Manager returning a tile each time rather than using a reference
		for (int i = 0; i < backgroundManager.getLength(); i++) {
			window.draw(backgroundManager.getTile(i));
		}
		
		window.draw(wizard.getSprite());


		clock.reset();
		

		window.display();
		
	}

	
}