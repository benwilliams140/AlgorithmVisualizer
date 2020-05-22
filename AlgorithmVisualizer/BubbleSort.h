#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm
{
public:
	BubbleSort(sf::RenderWindow&, int, int, int);
	~BubbleSort();
};

#endif