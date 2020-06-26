#ifndef MAIN_H
#define MAIN_H

#include <TGUI/TGUI.hpp>
#include <iostream>
#include "Common.h"

class Main
{
public:
	Main();
	~Main();

	void loop();

	void generateAlgorithm(std::string, int, int, int);

private:
	void init();

	void processInput();
	void update(float);
	void render();

	const unsigned int WINDOW_WIDTH = 1024;
	const unsigned int WINDOW_HEIGHT = 768;
	const std::string WINDOW_TITLE = "Algorithm Visualizer";

	sf::Vector2f viewSize;
	sf::VideoMode videoMode;
	sf::RenderWindow window;

	tgui::Gui gui;

	class ControlPanel* cp;
	class SortingAlgorithm* curAlgorithm;
};

#endif