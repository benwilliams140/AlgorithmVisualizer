#include "SortingAlgorithm.h"
#include "Box.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& _window, int _numValues, int _min, int _max) : window(_window)
{
	for (int _i = 0; _i < _numValues; ++_i)
	{
		int _value = rand() % (_max - _min + 1) + _min;
		float _x = window.getSize().x / 2 - (_i - (_numValues - 1) / 2) * Box::SIZE;
		Box* _box = new Box(_value, sf::Vector2f(_x, window.getSize().y / 4));
		boxes.push_back(_box);
		//std::cout << "initializing box: " << value << std::endl;
	}
}

SortingAlgorithm::~SortingAlgorithm()
{
	while (!boxes.empty())
	{
		delete boxes.back();
		boxes.pop_back();
	}
}

void SortingAlgorithm::sort()
{
}

void SortingAlgorithm::update(float _deltaTime)
{
}

void SortingAlgorithm::render()
{
	for (auto _it = boxes.begin(); _it != boxes.end(); ++_it)
	{
		Box* _box = *_it;
		_box->render(window);
	}
}

void SortingAlgorithm::compare(Box* _b1, Box* _b2)
{
	_b1->setColor(sf::Color::Yellow);
	_b2->setColor(sf::Color::Yellow);
}

void SortingAlgorithm::swap(Box* _b1, Box* _b2)
{
	_b1->setColor(sf::Color::Red);
	_b2->setColor(sf::Color::Red);
}