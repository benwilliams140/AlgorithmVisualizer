#include "Common.h"
#include "Box.h"

#include <string>

Box::Box(int _value, sf::Vector2f _pos)
	: value(_value), rect(sf::Vector2f(SIZE, SIZE))
{
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(2);
	rect.setPosition(_pos);
	rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));

	text.setFont(boxFont);
	text.setString(std::to_string(value));
	text.setCharacterSize(rect.getSize().y);
	text.setFillColor(sf::Color::Black);
	
	sf::FloatRect textBounds = text.getLocalBounds();
	
	text.setOrigin(textBounds.width / 2, textBounds.height);
	text.setPosition(rect.getPosition());
	//text.setScale(sf::Vector2f(mRect.getSize().x * 0.8f / textBounds.width, 1.0f));
}

Box::~Box()
{

}

void Box::update(float _deltaTime)
{
	// update rect position here

	text.setPosition(rect.getPosition());
}

void Box::render(sf::RenderWindow& _window)
{
	_window.draw(rect);
	_window.draw(text);
}