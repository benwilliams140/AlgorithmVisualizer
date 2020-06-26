#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <TGUI/TGUI.hpp>
#include <string>

class ControlPanel
{
public:
	ControlPanel(class Main*, sf::RenderWindow&, tgui::Gui&);
	~ControlPanel();

	void handleEvent(sf::Event&);
	void render();

private:
	void init();
	bool isNumber(std::string);

	sf::RenderWindow& window;
	tgui::Gui& gui;
	class Main* main;

	tgui::Panel::Ptr panel;
	tgui::Button::Ptr btnGenerate;
	tgui::ListBox::Ptr lboAlgorithms;
	tgui::EditBox::Ptr eboMinimum;
	tgui::EditBox::Ptr eboMaximum;
	tgui::Slider::Ptr sldNumValues;
	tgui::TextBox::Ptr tboNumValues;

	std::string algorithm;
	int numValues, min, max;
};

#endif