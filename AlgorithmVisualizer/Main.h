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

	const unsigned int mWindowWidth = 1024;
	const unsigned int mWindowHeight = 768;
	const std::string mWindowTitle = "Algorithm Visualizer";

	sf::Vector2f mViewSize;
	sf::VideoMode mVideoMode;
	sf::RenderWindow mWindow;

	tgui::Gui mGui;

	class ControlPanel* mCP;
	class SortingAlgorithm* mCurAlgorithm;
};

#endif