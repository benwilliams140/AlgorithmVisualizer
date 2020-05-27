#include "BubbleSort.h"

BubbleSort::BubbleSort(sf::RenderWindow& window, int numValues, int min, int max)
	: SortingAlgorithm(window, numValues, min, max)
{
	
}

BubbleSort::~BubbleSort()
{
	SortingAlgorithm::~SortingAlgorithm();
}