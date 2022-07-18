#include "HouseButton.h"


HouseButton::HouseButton()
{
	mCountFont.loadFromFile("fonts/TheConfessionFullRegular.ttf");


	mCountText.setFont(mCountFont);

	mCountText.setCharacterSize(30);
}


sf::RectangleShape& HouseButton::getButton(void)
{
	return mButton;
}

sf::Text& HouseButton::getCountText(void)
{
	return mCountText;
}

void HouseButton::setCountFont(sf::Font& newFont)
{
	mCountFont = newFont;
	mCountText.setFont(mCountFont);
}

void HouseButton::setCountTextString(std::string& newCount)
{
	mCountText.setString(newCount);
}

