#include <TGUI/TGUI.hpp>

#include "Main.h"
#include "ControlPanel.h"
#include "SortingAlgorithm.h"
#include "BubbleSort.h"

Main::Main() : mViewSize(mWindowWidth, mWindowHeight),
				mVideoMode(mViewSize.x, mViewSize.y),
				mWindow(mVideoMode, mWindowTitle, sf::Style::Default),
				mGui(mWindow)
{
	init();
}

Main::~Main()
{
	delete mCP;
	delete mCurAlgorithm;
}

void Main::loop()
{
	sf::Clock clock;
	mWindow.setFramerateLimit(60);

	while (mWindow.isOpen())
	{
		processInput();
		update(clock.restart().asSeconds());
		render();
	}
}

void Main::init()
{
	srand(time(NULL));

	boxFont.loadFromFile("assets/fonts/Cambria.ttf");

	mCP = new ControlPanel(this, mWindow, mGui);
}

void Main::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) mWindow.close();
	
		if (event.type == sf::Event::KeyPressed)
		{

		}

		mCP->handleEvent(event);
	}
}

void Main::update(float deltaTime)
{
	if(mCurAlgorithm != NULL) mCurAlgorithm->update(deltaTime);
}

void Main::render()
{
	mWindow.clear(sf::Color::White);

	if(mCurAlgorithm != NULL) mCurAlgorithm->render();
	mCP->render();

	mWindow.display();
}

void Main::generateAlgorithm(std::string algorithm, int numValues, int min, int max)
{
	if (mCurAlgorithm != NULL) delete mCurAlgorithm;

	if (algorithm == "Bubble Sort")
	{
		mCurAlgorithm = new BubbleSort(mWindow, numValues, min, max);
	}
}