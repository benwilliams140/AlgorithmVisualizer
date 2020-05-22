#include <SFML/Graphics.hpp>

#include "Common.h"
#include "SortingAlgorithm.h"
#include "BubbleSort.h"

const unsigned int windowWidth = 1024;
const unsigned int windowHeight = 768;
const std::string windowTitle = "Algorithm Visualizer";

sf::Vector2f viewSize(windowWidth, windowHeight);
sf::VideoMode videoMode(viewSize.x, viewSize.y);
sf::RenderWindow window(videoMode, windowTitle, sf::Style::Default);

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

	curAlgorithm = new BubbleSort(window, 0, 0, 0);
}

void cleanup()
{
	
}

void processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window.close();
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

	window.display();
}