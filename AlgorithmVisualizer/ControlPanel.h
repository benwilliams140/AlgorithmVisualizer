#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <SFML/Graphics.hpp>

class ControlPanel
{
public:
	ControlPanel(sf::RenderWindow&);
	~ControlPanel();

	void update(float);
	void render();

private:
	sf::RenderWindow& mWindow;
	sf::RectangleShape mBounds;
};

#endif