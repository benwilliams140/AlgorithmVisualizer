#include "BubbleSort.h"

BubbleSort::BubbleSort(sf::RenderWindow& _window, int _numValues, int _min, int _max)
	: SortingAlgorithm(_window, _numValues, _min, _max)
{
	
}

BubbleSort::~BubbleSort()
{
	SortingAlgorithm::~SortingAlgorithm();
}