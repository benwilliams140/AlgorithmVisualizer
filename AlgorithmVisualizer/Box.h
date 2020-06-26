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

	int getValue() const { return value; }

	void setColor(sf::Color _color) { rect.setOutlineColor(_color); }

	static const int SIZE = 50;

private:
	int						value;

	sf::RectangleShape		rect;
	sf::Text				text;
};

#endif