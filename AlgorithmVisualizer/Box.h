#ifndef BOX_H
#define BOX_H

#include <SFML/Graphics.hpp>

class Box
{
public:
	Box(int, sf::Vector2f);
	~Box();

	void update(float);
	void render(sf::RenderWindow&);

	int getValue() const { return mValue; }

	static const int size = 50;

private:
	int						mValue;

	sf::RectangleShape		mRect;
	sf::Text				mText;
};

#endif