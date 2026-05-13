#include <SFML/Graphics.hpp>

#include "Libraries/BackgroundGen.cpp"
#include "Libraries/BasicButton.h"
#include "Libraries/GameLogic.h"
#include "Libraries/PlayersHand.h"
#include "Libraries/PlayingCard.h"

sf::Vector2f getShapesCenter(const sf::Sprite &sp) {
    return {sp.getLocalBounds().size.x/2, sp.getLocalBounds().size.y/2};
}

int main() {
    auto gameLogic = GameLogic();
    long bet = 100;
    long money = 1000;
    long highMoney = money;

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({700, 900}), "Hello SFML!");

    auto appleGaramondFont = sf::Font(R"(Assets/Fonts/AppleGaramond.ttf)");
    auto BG = BackgroundGen(window,R"(.\Assets\green-felt-bg.png)");
    BG.setOrigin(sf::Vector2f( BG.getTextureDimensions())/2.f);
    BG.setPosition({sf::Vector2f(window.getSize())/2.f});
    BG.setScale({BG.getScale().x, BG.getScale().y * .65f});

    //Labels
    sf::Text scoreText{appleGaramondFont, "Score: " + std::to_string(money)};
    scoreText.setCharacterSize(25);
    scoreText.setOrigin(scoreText.getLocalBounds().size/2.f);
    scoreText.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-400});

    sf::Text highScore{appleGaramondFont, "High Score: " + std::to_string(highMoney)};
    highScore.setCharacterSize(20);
    highScore.setOrigin(highScore.getLocalBounds().size/2.f);
    highScore.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-370});



    ///Preparing Hands
    sf::Vector2f cardsScale = {0.5f, 0.5f};

    //Players hand and its label setup
    PlayersHand players_hand(window);
    players_hand.setCardsScale(cardsScale);
    players_hand.setPosition({window.getSize().x/2.f, window.getSize().y/2.f+150});
    players_hand.addNewRandomCard(2);
    sf::Text playersHandText{appleGaramondFont, "Yours hand: " + std::to_string(players_hand.getSum())};
    playersHandText.setCharacterSize(23);
    playersHandText.setPosition({players_hand.getPosition().x-65, players_hand.getPosition().y+110});


    //Croupiers hand and its label setup
    PlayersHand croupiers_hand(window);
    croupiers_hand.setCardsScale(cardsScale);
    croupiers_hand.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-150});
    croupiers_hand.addNewRandomCard(2);
    croupiers_hand.flipLastCard();
    sf::Text croupiersHandText{appleGaramondFont, "Croupiers hand: " + std::to_string(croupiers_hand.getSum())};
    croupiersHandText.setCharacterSize(23);
    croupiersHandText.setPosition({croupiers_hand.getPosition().x-80, croupiers_hand.getPosition().y-140});




    ///Prepering buttons
    auto quitButton = BasicButton({150,60},{100,20},[]() {
        exit(0);
    }, sf::Text(appleGaramondFont, "Quit"));
    //TODO: Fix white color
    //quitButton.setLabelColor(sf::Color::Black);

    sf::Vector2f playButtonsSize = {150,80};
    sf::Vector2f middleButtonPos = {window.getSize().x/2.f-playButtonsSize.x/2, window.getSize().y/2.f + 330};
    BasicButton hitButton = BasicButton(playButtonsSize,{middleButtonPos.x-200, middleButtonPos.y},[&]() {
        gameLogic.HitMe(players_hand, croupiers_hand);
    }, sf::Text(appleGaramondFont, "Hit Me!"));
    hitButton.isEnabled(false);

    BasicButton doubleButton = BasicButton(playButtonsSize,{middleButtonPos.x+200, middleButtonPos.y},[&]() {
        gameLogic.DoubleMe(players_hand, croupiers_hand, bet);
    }, sf::Text(appleGaramondFont, "Double Me!"));
    doubleButton.isEnabled(false);

    BasicButton standButton = BasicButton(playButtonsSize,middleButtonPos,[&]() {
        gameLogic.Stand(players_hand, croupiers_hand);
    }, sf::Text(appleGaramondFont, "Stand"));
    doubleButton.isEnabled(false);










    while (window.isOpen()) {

        hitButton.isEnabled(false);
        standButton.isEnabled(false);
        doubleButton.isEnabled(false);



        switch (gameLogic.getState()) {
            case WON:
                money += 2 * bet;
                break;
            case LOST:

                break;
            case BLACKJACK:
                money += 2.5 * bet;
                break;
            case TIE:
                break;
            case IN_PROGRESS:
                hitButton.isEnabled(true);
                standButton.isEnabled(true);
                doubleButton.isEnabled(true);
                break;
            case PLACING_BETS:
                break;
        }





        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>() ) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::Escape:
                        exit(0);
                        break;

                    default:
                        break;
                }

            }



            quitButton.EventHandler(event, window);
            hitButton.EventHandler(event, window);
            standButton.EventHandler(event, window);
            doubleButton.EventHandler(event, window);
        }
        //Game Refresh
        playersHandText.setString("Yours hand: " + std::to_string(players_hand.getSum()));
        croupiersHandText.setString("Croupiers hand: " + std::to_string(croupiers_hand.getSum()));

        window.clear({20,20,20});
        //Background
        BG.draw(window);

        //Labels
        window.draw(playersHandText);
        window.draw(croupiersHandText);

        //Buttons
        quitButton.draw(window);
        hitButton.draw(window);
        standButton.draw(window);
        doubleButton.draw(window);

        //Hands
        players_hand.drawHand(window);
        croupiers_hand.drawHand(window);


        window.draw(scoreText);
        window.draw(highScore);


        //Display
        window.display();
    }



    return 0;
}