#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

//#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class ControlPanel
{
public:
	ControlPanel(sf::RenderWindow&/*, tgui::Gui&*/);
	~ControlPanel();

	void handleEvent(sf::Event&);
	void render();

private:
	void init();

	sf::RenderWindow& mWindow;
	/*tgui::Gui& mGui;

	tgui::Panel::Ptr mPanel;
	tgui::Button::Ptr mBtnGenerate;
	tgui::ListBox::Ptr mLboAlgorithms;
	tgui::EditBox::Ptr mEboMinimum;
	tgui::EditBox::Ptr mEboMaximum;
	tgui::RangeSlider::Ptr mSldNumValues;*/
};

#endif