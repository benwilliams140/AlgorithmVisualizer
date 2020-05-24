#include "ControlPanel.h"

ControlPanel::ControlPanel(sf::RenderWindow& window/*, tgui::Gui& gui*/)
	: mWindow(window)//, mGui(gui)
{
	init();
}

ControlPanel::~ControlPanel()
{

}

void ControlPanel::handleEvent(sf::Event& event)
{
	//mGui.handleEvent(event);
}

void ControlPanel::render()
{
	//mGui.draw();
}

void ControlPanel::init()
{
	/*
	mPanel = tgui::Panel::create({ "100%", "50%" });
	mPanel->setPosition(0, mWindow.getSize().y / 2);
	mGui.add(mPanel);

	mLboAlgorithms = tgui::ListBox::create();
	mLboAlgorithms->addItem("Bubble Sort");
	mPanel->add(mLboAlgorithms);

	mSldNumValues = tgui::RangeSlider::create(1, 25);
	mPanel->add(mSldNumValues);

	mEboMinimum = tgui::EditBox::create();
	mPanel->add(mEboMinimum);
	
	mEboMaximum = tgui::EditBox::create();
	mPanel->add(mEboMaximum);

	mBtnGenerate = tgui::Button::create("Generate");
	mBtnGenerate->setPosition({0, 0});
	mPanel->add(mBtnGenerate);
	*/
}
