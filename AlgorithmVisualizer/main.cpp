//#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

#include "Common.h"
#include "ControlPanel.h"
#include "SortingAlgorithm.h"
#include "BubbleSort.h"

const unsigned int windowWidth = 1024;
const unsigned int windowHeight = 768;
const std::string windowTitle = "Algorithm Visualizer";

sf::Vector2f viewSize(windowWidth, windowHeight);
sf::VideoMode videoMode(viewSize.x, viewSize.y);
sf::RenderWindow window(videoMode, windowTitle, sf::Style::Default);

//tgui::Gui gui(window);

ControlPanel* cp;
SortingAlgorithm* curAlgorithm;

sf::Font boxFont;

void init();
void cleanup();

void processInput();
void update(float);
void render();

int main()
{
	init();

	sf::Clock clock;
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		processInput();
		update(clock.restart().asSeconds());
		render();
	}

	cleanup();

	return 0;
}

void init()
{
	srand(time(NULL));

	boxFont.loadFromFile("assets/fonts/Cambria.ttf");

	cp = new ControlPanel(window/*, gui*/);
	curAlgorithm = new BubbleSort(window, 6, 1, 10);
}

void cleanup()
{
	delete cp;
	delete curAlgorithm;
}

void processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (/*event.type == sf::Event::Closed || */event.key.code == sf::Keyboard::Escape) window.close();
	
		if (event.type == sf::Event::KeyPressed)
		{

		}

		cp->handleEvent(event);
	}
}

void update(float deltaTime)
{
	curAlgorithm->update(deltaTime);
}

void render()
{
	window.clear(sf::Color::White);

	curAlgorithm->render();
	cp->render();

	window.display();
}