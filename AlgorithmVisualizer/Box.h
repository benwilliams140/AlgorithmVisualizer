#ifndef BOX_H
#define BOX_H

#include <SFML/Graphics.hpp>

class Box
{
public:
	Box(int, sf::Vector2f, sf::Vector2f);
	~Box();

	void update(float);
	void render(sf::RenderWindow&);

	int getValue() const { return mValue; }

private:
	int						mValue;

	sf::RectangleShape		mRect;
	sf::Text				mText;
};

#endif