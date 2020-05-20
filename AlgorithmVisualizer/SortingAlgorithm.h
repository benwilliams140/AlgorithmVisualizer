#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>

class SortingAlgorithm
{
public:
	SortingAlgorithm(sf::RenderWindow);
	~SortingAlgorithm();

	virtual void sort();

	void update(float);
	void render();

private:
	sf::RenderWindow mWindow;
	
	std::vector<void* ()> mSteps;

	std::vector<class Box*> mBoxes;
	std::vector<int> values;
};

#endif