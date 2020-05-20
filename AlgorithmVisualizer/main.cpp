#include <SFML/Graphics.hpp>

const unsigned int windowWidth = 1024;
const unsigned int windowHeight = 768;
const std::string windowTitle = "Algorithm Visualizer";

sf::Vector2f viewSize(windowWidth, windowHeight);
sf::VideoMode videoMode(viewSize.x, viewSize.y);
sf::RenderWindow window(videoMode, windowTitle, sf::Style::Default);

void init();
void cleanup();

void processInput();
void update();
void render();

int main()
{
	while (window.isOpen())
	{
		processInput();
		update();
		render();
	}

	cleanup();

	return 0;
}

void init()
{

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

void update()
{

}

void render()
{
	window.clear(sf::Color::White);

	window.display();
}