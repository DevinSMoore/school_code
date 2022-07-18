#include "KalahGraphics.h"
#define BTN_H 50.0f
#define BTN_W 125.0f
#define WINDOW_H 700
#define WINDOW_W 1500


Kalah::Kalah()
{
    // Passing Kalah board configuration to Board then initializing board
    mpButtonArray = new std::vector<HouseButton>(2 * KALAH_SIDE_HOUSE_COUNT);
    mpBackgroundTexture = new sf::Texture;
    mpBackgroundTexture->loadFromFile("art/gameBackground.png");
    mpGameBackgroundSprite = new sf::Sprite(*mpBackgroundTexture);
}

Kalah::~Kalah()
{
    std::cout << "Hit Kalah destructor...." << std::endl;
    mpButtonArray->clear();
    delete mpButtonArray;
    delete mpGameBackgroundSprite;
}

std::vector<HouseButton>*& Kalah::getButtonArrayPtr(void)
{
    return mpButtonArray;
}

sf::Sprite*& Kalah::getBackgroundSpritePtr(void)
{
    return mpGameBackgroundSprite;
}

// sets a players name
// Input Parameters:
// std::string: name to set
// int: player that we're setting the name of; 1 = p1; 2 = p2
void Kalah::setPlayerName(const int& whichPlayer, std::string& playerNameToSet)
{
    // Just a font that looks nice
    sf::Font font, font2;
    int introWindowWidth = 400, introWindowHeight = 200;
    font.loadFromFile("fonts/TheConfessionFullRegular.ttf");
    font2.loadFromFile("fonts/Montserrat-Regular.ttf");
    char readChar = '0';
    sf::RenderWindow namePromptWindow(sf::VideoMode(introWindowWidth, introWindowHeight), "Welcome to Kalah! - Devin Moore", sf::Style::Close | sf::Style::Titlebar);
    std::string playerName = "", testString = "";
    
    
    sf::Text introText, nameText;
    
    introText.setFont(font);
    introText.setCharacterSize(28);
    introText.setPosition(55.0f, 5.0f);
    introText.setFillColor(sf::Color::Black);
   
    nameText.setFont(font2);
    nameText.setCharacterSize(20);
    nameText.setPosition(introWindowWidth / 2.2f, introWindowHeight / 2.0f);
    nameText.setFillColor(sf::Color::Black);

    sf::Texture nameBoxBackground;
    nameBoxBackground.loadFromFile("art/introBackground.png");
    sf::Sprite bckGndSprite(nameBoxBackground); // load in background image for name enter box


    if(whichPlayer == 1)
    { 
        introText.setString("Please enter player ones name\nthen press enter to proceed....");
    }
    else
    {
        introText.setString("Please enter player twos name\nthen press enter to proceed....");
    }


   
    while (namePromptWindow.isOpen())
    {
        if(playerName.size() > 0) // This just readjusts the origin of the character string so that it remains roughly in the center of the screen
        {
            float newHorizontalOrigin = ((float)playerName.size() * (nameText.getCharacterSize() / 4.5f));
           // std::cout << "newHorizOrig: " << newHorizontalOrigin << std::endl;
            nameText.setOrigin(newHorizontalOrigin, 10);
        }
        

      
        namePromptWindow.clear();
        namePromptWindow.draw(bckGndSprite);
        namePromptWindow.draw(introText);
        namePromptWindow.draw(nameText);
        namePromptWindow.display();

        sf::Event introEvent;
        while (namePromptWindow.pollEvent(introEvent))
        {


            switch (introEvent.type)
            {
            case sf::Event::Closed:
                // std::cout << "Intro window closing...." << std::endl;
                namePromptWindow.close();
                
                break;
            case sf::Event::KeyReleased:
                if (introEvent.key.code == sf::Keyboard::Backspace)
                {
                   // std::cout << "Hit backspace event...." << std::endl;
                    playerName = playerName.substr(0, playerName.size() - 1); // This will delete the last char in the string
                    nameText.setString(playerName); // set nameText string to be updated on window during next loop
                }
                else if (introEvent.key.code == sf::Keyboard::Enter)
                {
                    if(!playerName.empty())
                    {
                        playerNameToSet = playerName;
                        namePromptWindow.close();
                    }
                    else
                    {
                        introWarning(NO_NAME_ENTERED);
                    }
                }
                break;
            case sf::Event::TextEntered:
                //std::cout << "Hit text entered event...." << std::endl;
                readChar = introEvent.text.unicode;

                if (((int)(playerName.size()) > 30)) { // If we enter more than 30 chars a warning message will pop up, and name will be cleared
                    playerName.clear();
                    nameText.setString(playerName);
                    introWarning(NAME_TOO_LONG);
                    break; }

                if(readChar == ' ' || readChar == '\'' || (readChar <= 'z' && readChar >= 'a') || (readChar <= 'Z' && readChar >= 'A') || (readChar <= '9' && readChar >= '0')) // Just keeping it to numbers English characters, the apostrophe, and the space
                {
                    //std::cout << "Char read in: " << readChar << std::endl;
                    playerName += introEvent.text.unicode; // Grabbing the character enterd
                    nameText.setString(playerName); // set nameText string to be updated on window during next loop
                }

                break;

            default:
                
                break;
            }
        }
    }
}


// Prints a splash screen then gathers both players names
// Input Parameters:
//		std::string: string P1s name is goign to be placed into
//		std::string: string for P2s name
void Kalah::splashScreen(std::string& p1Name, std::string& p2Name)
{
    sf::RenderWindow splashScreen(sf::VideoMode(400, 300), "Welcome to Kalah! - Devin Moore", sf::Style::Close | sf::Style::Titlebar);
    sf::Event splashEvent;

    sf::Texture splashTexture;
    splashTexture.loadFromFile("art/splashScreen.png");
    sf::Sprite splashSprite(splashTexture);

    splashScreen.clear();
    splashScreen.draw(splashSprite);
    splashScreen.display();

    while (splashScreen.isOpen())
    {
        while (splashScreen.pollEvent(splashEvent))
        {
            switch (splashEvent.type)
            {
            case sf::Event::Closed:
                splashScreen.close();
                break;
            case sf::Event::KeyReleased:
                if (splashEvent.key.code == sf::Keyboard::Enter)
                {
                    splashScreen.close();
                    setPlayerName(P1, p1Name);
                    setPlayerName(P2, p2Name);
                }
                break;
            default:

                break;
            }
        }
    }
}

// This will show an error message on the screen
// Input Parameters:
//		std::string representing the message to be displayd
void Kalah::introWarning(const std::string& warningMessage)
{
    // Just a font that looks nice
    sf::Font font;
    font.loadFromFile("fonts/TheConfessionFullRegular.ttf");
    sf::Text warningText;
    warningText.setFont(font);
    warningText.setString(warningMessage);
    warningText.setFillColor(sf::Color::Black);
    warningText.setPosition(7.0f, 0.0f);
    sf::RenderWindow warningWindow(sf::VideoMode(warningText.getString().getSize() * (warningText.getCharacterSize() / 3), WINDOW_H / 16), "Beep Boop - I don't like what you did -> Press Enter to continue....", sf::Style::Close | sf::Style::Titlebar);
   
    while(warningWindow.isOpen())
    {
        warningWindow.clear(sf::Color::Cyan);

        warningWindow.draw(warningText);
        warningWindow.display();

        sf::Event warningEvent;
        while (warningWindow.pollEvent(warningEvent))
        {
            switch (warningEvent.type)
            {
            case sf::Event::Closed:
                std::cout << "Warning window closing...." << std::endl;
                warningWindow.close();
                break;
            case sf::Event::KeyReleased:
                if (warningEvent.key.code == sf::Keyboard::Enter)
                {
                    warningWindow.close();
                }
                break;
            default:

                break;
            }
        }

    }
}

// This will go through and set all of the base values for all of the buttons
// Input Parameters:
//      sf::RenderWindow: reference to the game window that you want to display buttons onto.
void Kalah::initializeButtons(sf::RenderWindow& gameWindow)
{
    int i = 0;
    std::string tempString = "";
    sf::Vector2f BtnOrigin(BTN_W / (float)2, BTN_H / (float)2);
    sf::Vector2f BtnSize(BTN_W, BTN_H);

    for (; i < 6; i++)
    {
        mpButtonArray->at(i).getButton().setOrigin(BtnOrigin);
        mpButtonArray->at(i).getButton().setSize(BtnSize);
        mpButtonArray->at(i).getButton().setPosition(350.0f + (i * 156.0f), 130.0f);
        mpButtonArray->at(i).getCountText().setPosition(390.0f + (i * 156.0f), 310.0f);
        mpButtonArray->at(i).getCountText().setFillColor(sf::Color::Black);
    }

    for (int j = 0; i < 12; i++, j++)
    {
        mpButtonArray->at(i).getButton().setOrigin(BtnOrigin);
        mpButtonArray->at(i).getButton().setSize(BtnSize);
        mpButtonArray->at(i).getButton().setPosition(350.0f + (j * 156.0f), 580.0f);
        mpButtonArray->at(i).getCountText().setPosition(390.0f + (j * 156.0f), 500.0f);
        mpButtonArray->at(i).getCountText().setFillColor(sf::Color::Black);

    }
    
    for (i = 0; i < 12; i++)
    {
        tempString = "4";
        tempString += " ";
        tempString += std::to_string(i);
        gameWindow.draw(mpButtonArray->at(i).getButton());
        mpButtonArray->at(i).setCountTextString(tempString); // Setting all to 4 intitially
        gameWindow.draw(mpButtonArray->at(i).getCountText());
    }
}