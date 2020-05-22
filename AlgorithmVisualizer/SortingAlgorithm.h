#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>

class SortingAlgorithm
{
public:
	SortingAlgorithm(sf::RenderWindow&, int, int, int);
	~SortingAlgorithm();

	virtual void sort();

	void update(float);
	void render();

private:
	void compare(class Box*, class Box*);
	void swap(class Box*, class Box*);

	sf::RenderWindow& mWindow;

	std::vector<class Box*> mBoxes;
};

#endif