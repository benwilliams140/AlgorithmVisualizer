#include "ControlPanel.h"
#include "Main.h"

ControlPanel::ControlPanel(Main* main, sf::RenderWindow& window, tgui::Gui& gui)
	: mWindow(window), mGui(gui), mMain(main)
{
	numValues = 10;
	min = 0;
	max = 10;

	init();
}

ControlPanel::~ControlPanel()
{

}

void ControlPanel::handleEvent(sf::Event& event)
{
	mGui.handleEvent(event);
}

void ControlPanel::render()
{
	mGui.draw();
}

void ControlPanel::init()
{
	mPanel = tgui::Panel::create({ "100%", "50%" });
	mPanel->setPosition(0, mWindow.getSize().y / 2);
	mGui.add(mPanel);

	mLboAlgorithms = tgui::ListBox::create();
	mLboAlgorithms->addItem("Bubble Sort");
	algorithm = mLboAlgorithms->getItemByIndex(0);
	mLboAlgorithms->setSelectedItem(algorithm);
	mLboAlgorithms->setPosition(5, 5);
	mPanel->add(mLboAlgorithms);

	mSldNumValues = tgui::Slider::create(1, 25);
	mSldNumValues->setPosition(mLboAlgorithms->getPosition().x, mLboAlgorithms->getSize().y + 10);
	mSldNumValues->setValue(numValues);
	mSldNumValues->connect(tgui::Signals::Slider::ValueChanged, [&]()
		{
			numValues = (int)mSldNumValues->getValue();
		});
	mPanel->add(mSldNumValues);

	mEboMinimum = tgui::EditBox::create();
	mEboMinimum->setPosition(mLboAlgorithms->getSize().x + 10, 5);
	mEboMinimum->setText(std::to_string(min));
	mEboMinimum->connect(tgui::Signals::EditBox::TextChanged, [&]() 
		{
			if (isNumber(mEboMinimum->getText()))
			{
				std::string temp = mEboMinimum->getText();
				min = std::stoi(temp);
				min = min < 0 ? 0 : min;
			}
		});
	mPanel->add(mEboMinimum);
	
	mEboMaximum = tgui::EditBox::create();
	mEboMaximum->setPosition(mEboMinimum->getPosition().x, mEboMinimum->getSize().y + 10);
	mEboMaximum->setText(std::to_string(max));
	mEboMaximum->connect(tgui::Signals::EditBox::TextChanged, [&]() 
		{
			if (isNumber(mEboMaximum->getText()))
			{
				std::string temp = mEboMaximum->getText();
				max = std::stoi(temp);
				max = max > 100 ? 100 : max;
			}
		});
	mPanel->add(mEboMaximum);

	mBtnGenerate = tgui::Button::create("Generate");
	mBtnGenerate->connect(tgui::Signals::Button::Pressed, [&]()
		{
			mMain->generateAlgorithm(algorithm, numValues, min, max);
		});
	mBtnGenerate->setPosition(mEboMinimum->getPosition().x, mEboMaximum->getPosition().y + mEboMaximum->getSize().y + 5);
	mPanel->add(mBtnGenerate);
}

bool ControlPanel::isNumber(std::string s)
{
	for (int i = 0; i < s.length(); ++i)
		if (!isdigit(s[i])) return false;

	return true;
}