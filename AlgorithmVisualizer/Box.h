#ifndef BOX_H
#define BOX_H

#include <SFML/Graphics.hpp>

class Box
{
public:
	Box(int);
	~Box();

	void update(float);
	void render(sf::RenderWindow);

	int getValue() const { return mValue; }

private:
	int mValue;
};

#endif