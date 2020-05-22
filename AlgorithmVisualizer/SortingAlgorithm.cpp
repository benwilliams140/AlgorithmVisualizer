#include "SortingAlgorithm.h"
#include "Box.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& window, int numValues, int min, int max) : mWindow(window)
{
	mBoxes.push_back(new Box(100, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(50, 50)));
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