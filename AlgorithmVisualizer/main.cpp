#include <TGUI/TGUI.hpp>

#include "Main.h"
#include "ControlPanel.h"
#include "SortingAlgorithm.h"
#include "BubbleSort.h"

Main::Main() : viewSize(WINDOW_WIDTH, WINDOW_HEIGHT),
				videoMode(viewSize.x, viewSize.y),
				window(videoMode, WINDOW_TITLE, sf::Style::Default),
				gui(window)
{
	init();
}

Main::~Main()
{
	delete cp;
	delete curAlgorithm;
}

void Main::loop()
{
	sf::Clock _clock;
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		processInput();
		update(_clock.restart().asSeconds());
		render();
	}
}

void Main::init()
{
	srand(time(NULL));

	boxFont.loadFromFile("assets/fonts/Cambria.ttf");

	cp = new ControlPanel(this, window, gui);
}

void Main::processInput()
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed) window.close();
	
		if (_event.type == sf::Event::KeyPressed)
		{

		}

		cp->handleEvent(_event);
	}
}

void Main::update(float _deltaTime)
{
	if(curAlgorithm != NULL) curAlgorithm->update(_deltaTime);
}

void Main::render()
{
	window.clear(sf::Color::White);

	if(curAlgorithm != NULL) curAlgorithm->render();
	cp->render();

	window.display();
}

void Main::generateAlgorithm(std::string _algorithm, int _numValues, int _min, int _max)
{
	if (curAlgorithm != NULL) delete curAlgorithm;

	if (_algorithm == "Bubble Sort")
	{
		curAlgorithm = new BubbleSort(window, _numValues, _min, _max);
	}
}