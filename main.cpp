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

	
	
	//For testing on a large monitor, simply scaling by 3 is fine, but I will probably want to tie it to Window Size
	
	
	
	//This creates the position for the wizard, to have it centered, I grab the pixel size of the wizard multiplied by the game scale and half it to offset.
	//Is this potentially off by a pixel?  (Based on theory not observation)
	int windowWidth = window.getSize().x;
	int windowHeight = window.getSize().y;

	float gameScale = 3;

	Wizard wizard(windowWidth , windowHeight , gameScale);

	BackgroundManager backgroundManager = BackgroundManager();

	//This shit seems so pointless to me, but debug throws a hissy fit if it's not a wide string
	String grassTilePath = "graphics/GrassTiles.png";
	std::wstring grassTilePathW = grassTilePath.toWideString();

	backgroundManager.generate(windowWidth, windowHeight, gameScale, grassTilePathW);

	Clock clock;
	clock.start();

	while (window.isOpen()) {

		//optional can either hold a value or be empty, so in this case, I suppose it's whether or not there is an event from the window, it surprises me that this is a subloop
		//it seems like it could just be an if statement, but maybe this works better with timing, i.e. you can hold down the x button otherwise lag from elsewhere in the loop might make
		//magical moments where you could click without the event being caught.  ...maybe
		while (const std::optional event = window.pollEvent())
		{
			//So, I don't really understand -> yet 
			if (event->is<Event::Closed>())
				window.close();
		}

		window.clear();
		

		for (int i = 0; i < backgroundManager.getLength(); i++) {
			window.draw(backgroundManager.getTile(i));
		}
		
		window.draw(wizard.getSprite());

		clock.reset();
		
		window.display();
		
	}

	
}