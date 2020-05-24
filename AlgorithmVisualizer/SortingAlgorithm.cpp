#include "SortingAlgorithm.h"
#include "Box.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& window, int numValues, int min, int max) : mWindow(window)
{
	for (int i = 0; i < numValues; ++i)
	{
		int value = rand() % (max - min + 1) + min;
		float x = window.getSize().x / 2 - (i - (numValues - 1) / 2) * Box::size;
		Box* box = new Box(value, sf::Vector2f(x, window.getSize().y / 4));
		mBoxes.push_back(box);
	}
}

SortingAlgorithm::~SortingAlgorithm()
{
	while (!mBoxes.empty())
	{
		delete mBoxes.back();
		mBoxes.pop_back();
	}
}

void SortingAlgorithm::sort()
{
}

void SortingAlgorithm::update(float deltaTime)
{
}

void SortingAlgorithm::render()
{
	for (auto it = mBoxes.begin(); it != mBoxes.end(); ++it)
	{
		Box* box = *it;
		box->render(mWindow);
	}
}

void SortingAlgorithm::compare(Box* b1, Box* b2)
{
	
}

void SortingAlgorithm::swap(Box* b1, Box* b2)
{

}