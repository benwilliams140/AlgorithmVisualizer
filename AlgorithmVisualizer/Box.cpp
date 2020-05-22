#include "Common.h"
#include "Box.h"

#include <string>

Box::Box(int value, sf::Vector2f pos)
	: mValue(value), mRect(sf::Vector2f(size, size))
{
	mRect.setOutlineColor(sf::Color::Black);
	mRect.setOutlineThickness(2);
	mRect.setPosition(pos);
	mRect.setOrigin(sf::Vector2f(mRect.getSize().x / 2, mRect.getSize().y / 2));

	mText.setFont(boxFont);
	mText.setString(std::to_string(mValue));
	mText.setCharacterSize(mRect.getSize().y);
	mText.setFillColor(sf::Color::Black);
	
	sf::FloatRect textBounds = mText.getLocalBounds();
	//mText.setOrigin(textBounds.width / 2, textBounds.height / 2);
	//mText.setPosition(sf::Vector2f(mRect.getPosition().x - textBounds.width / 2,
	//							mRect.getPosition().y - textBounds.height / 2));
	
	mText.setOrigin(textBounds.width / 2, textBounds.height);
	mText.setPosition(mRect.getPosition());
	mText.setScale(sf::Vector2f(mRect.getSize().x * 0.8f / textBounds.width, 1.0f));
}

Box::~Box()
{

}

void Box::update(float deltaTime)
{
	// update rect position here

	mText.setPosition(mRect.getPosition());
}

void Box::render(sf::RenderWindow& window)
{
	window.draw(mRect);
	window.draw(mText);
}