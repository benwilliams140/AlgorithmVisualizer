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

	sf::RenderWindow& mWindow;
	tgui::Gui& mGui;
	class Main* mMain;

	tgui::Panel::Ptr mPanel;
	tgui::Button::Ptr mBtnGenerate;
	tgui::ListBox::Ptr mLboAlgorithms;
	tgui::EditBox::Ptr mEboMinimum;
	tgui::EditBox::Ptr mEboMaximum;
	tgui::Slider::Ptr mSldNumValues;
	tgui::TextBox::Ptr mTboNumValues;

	std::string algorithm;
	int numValues, min, max;
};

#endif