#include "ControlPanel.h"
#include "Main.h"

ControlPanel::ControlPanel(Main* _main, sf::RenderWindow& _window, tgui::Gui& _gui)
	: window(_window), gui(_gui), main(_main)
{
	numValues = 10;
	min = 0;
	max = 10;

	init();
}

ControlPanel::~ControlPanel()
{

}

void ControlPanel::handleEvent(sf::Event& _event)
{
	gui.handleEvent(_event);
}

void ControlPanel::render()
{
	gui.draw();
}

void ControlPanel::init()
{
	panel = tgui::Panel::create({ "100%", "50%" });
	panel->setPosition(0, window.getSize().y / 2);
	gui.add(panel);

	lboAlgorithms = tgui::ListBox::create();
	lboAlgorithms->addItem("Bubble Sort");
	algorithm = lboAlgorithms->getItemByIndex(0);
	lboAlgorithms->setSelectedItem(algorithm);
	lboAlgorithms->setPosition(5, 5);
	panel->add(lboAlgorithms);

	sldNumValues = tgui::Slider::create(1, 20);
	sldNumValues->setPosition(lboAlgorithms->getPosition().x, lboAlgorithms->getSize().y + 10);
	sldNumValues->setValue(numValues);
	sldNumValues->connect(tgui::Signals::Slider::ValueChanged, [&]()
		{
			numValues = (int)sldNumValues->getValue();
			tboNumValues->setText(std::to_string(numValues));
		});
	panel->add(sldNumValues);

	tboNumValues = tgui::TextBox::create();
	tboNumValues->setPosition(sldNumValues->getSize().x + 10, sldNumValues->getPosition().y);
	tboNumValues->setText(std::to_string(numValues));
	tboNumValues->setSize(25, 20);
	panel->add(tboNumValues);

	eboMinimum = tgui::EditBox::create();
	eboMinimum->setPosition(lboAlgorithms->getSize().x + 10, 5);
	eboMinimum->setText(std::to_string(min));
	eboMinimum->connect(tgui::Signals::EditBox::Unfocused, [&]() 
		{
			if (isNumber(eboMinimum->getText()))
			{
				std::string _temp = eboMinimum->getText();
				min = std::stoi(_temp);
				min = min < 0 ? 0 : min;
				eboMinimum->setText(std::to_string(min));
			}
		});
	eboMinimum->connect(tgui::Signals::EditBox::Clicked, [&]()
		{
			eboMinimum->selectText();
		});
	panel->add(eboMinimum);
	
	eboMaximum = tgui::EditBox::create();
	eboMaximum->setPosition(eboMinimum->getPosition().x, eboMinimum->getSize().y + 10);
	eboMaximum->setText(std::to_string(max));
	eboMaximum->connect(tgui::Signals::EditBox::Unfocused, [&]() 
		{
			if (isNumber(eboMaximum->getText()))
			{
				std::string _temp = eboMaximum->getText();
				max = std::stoi(_temp);
				max = max > 100 ? 100 : max;
				eboMaximum->setText(std::to_string(max));
			}
		});
	eboMaximum->connect(tgui::Signals::EditBox::Clicked, [&]()
		{
			eboMaximum->selectText();
		});
	panel->add(eboMaximum);

	btnGenerate = tgui::Button::create("Generate");
	btnGenerate->connect(tgui::Signals::Button::Pressed, [&]()
		{
			algorithm = lboAlgorithms->getSelectedItem();

			if (min < max)
				main->generateAlgorithm(algorithm, numValues, min, max);
		});
	btnGenerate->setPosition(eboMinimum->getPosition().x, eboMaximum->getPosition().y + eboMaximum->getSize().y + 5);
	panel->add(btnGenerate);
}

bool ControlPanel::isNumber(std::string _s)
{
	if (_s.length() == 0) return false;

	for (int i = 0; i < _s.length(); ++i)
	{
		if (_s[i] == '-') continue;
		if (!isdigit(_s[i])) return false;
	}

	return true;
}