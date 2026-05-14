#include <algorithm>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Libraries/BackgroundGen.cpp"
#include "Libraries/BasicButton.h"
#include "Libraries/BetPlacer.h"
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

    sf::RenderWindow window(sf::VideoMode({700, 800}), "Hello SFML!");

    auto appleGaramondFont = sf::Font(R"(Assets/Fonts/AppleGaramond.ttf)");
    auto BG = BackgroundGen(window,R"(Assets/green-felt-bg.png)");
    BG.setOrigin(sf::Vector2f( BG.getTextureDimensions())/2.f);
    BG.setPosition({sf::Vector2f(window.getSize())/2.f});
    BG.setScale({BG.getScale().x, BG.getScale().y * .75f});

    //Labels
    sf::Text scoreText{appleGaramondFont, "Score: " + std::to_string(money)};
    scoreText.setCharacterSize(35);
    scoreText.setOrigin(scoreText.getLocalBounds().size/2.f);
    scoreText.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-380});

    sf::Text highScore{appleGaramondFont, "High Score: " + std::to_string(highMoney)};
    highScore.setCharacterSize(25);
    highScore.setOrigin(highScore.getLocalBounds().size/2.f);
    highScore.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-340});



    ///Preparing Hands
    sf::Vector2f cardsScale = {0.45f, 0.45f};

    //Players hand and its label setup
    PlayersHand players_hand(window);
    players_hand.setCardsScale(cardsScale);
    players_hand.setPosition({window.getSize().x/2.f, window.getSize().y/2.f+170});
    players_hand.addNewRandomCard(2);
    sf::Text playersHandText{appleGaramondFont, "Yours hand: " + std::to_string(players_hand.getSum())};
    playersHandText.setCharacterSize(23);
    playersHandText.setPosition({players_hand.getPosition().x-65, players_hand.getPosition().y+95});


    //Croupiers hand and its label setup
    PlayersHand croupiers_hand(window);
    croupiers_hand.setCardsScale(cardsScale);
    croupiers_hand.setPosition({window.getSize().x/2.f, window.getSize().y/2.f-170});
    croupiers_hand.addNewRandomCard(2);
    croupiers_hand.flipLastCard();
    sf::Text croupiersHandText{appleGaramondFont, "Croupiers hand: " + std::to_string(croupiers_hand.getSum())};
    croupiersHandText.setCharacterSize(23);
    croupiersHandText.setPosition({croupiers_hand.getPosition().x-80, croupiers_hand.getPosition().y-125});




    ///Prepering buttons

    sf::Vector2f playButtonsSize = {150,80};
    sf::Vector2f middleButtonPos = {window.getSize().x/2.f-playButtonsSize.x/2, window.getSize().y/2.f + 310};
    BasicButton hitButton = BasicButton(playButtonsSize,{middleButtonPos.x-200, middleButtonPos.y},[&]() {
        gameLogic.HitMe(players_hand, croupiers_hand);
    }, sf::Text(appleGaramondFont, "Hit Me!"));
    hitButton.isEnabled(false);

    bool hasDoubled = false;
    BasicButton doubleButton = BasicButton(playButtonsSize,{middleButtonPos.x+200, middleButtonPos.y},[&]() {
        gameLogic.DoubleMe(players_hand, croupiers_hand, bet);
        hasDoubled = true;
        money -= bet/2;
    }, sf::Text(appleGaramondFont, "Double Me!"));
    doubleButton.isEnabled(false);

    BasicButton standButton = BasicButton(playButtonsSize,middleButtonPos,[&]() {
        gameLogic.Stand(players_hand, croupiers_hand);
    }, sf::Text(appleGaramondFont, "Stand"));
    doubleButton.isEnabled(false);


    BetPlacer bet_placer(&bet,appleGaramondFont,{window.getSize().x/2.f, window.getSize().y/2.f-12});
    bet_placer.increaseBetButton.setOnClick([&bet, &money]() {
        int powOf10 = std::log10(bet);
        bet += std::pow(10, powOf10);
        bet = std::min(bet, money);
    });
    bet_placer.decreaseBetButton.setOnClick([&]() {
        int powOf10 = std::log10(bet);
        if (bet/std::pow(10, powOf10) < 2) {
            powOf10--;
        }
        bet -= std::pow(10, powOf10);
        bet = std::max(bet, 1l);
    });
    bet_placer.placeBetButton.setOnClick([&]() {
        money -= bet;
        gameLogic.PlaceBet(players_hand, croupiers_hand);
    });






//App working loop

    while (window.isOpen()) {
        //Setting up controls
        if (gameLogic.getState() == IN_PROGRESS) {
            hitButton.isEnabled(true);
            standButton.isEnabled(true);
            doubleButton.isEnabled(!hasDoubled && bet < money && players_hand.getCardAmount() == 2);
        }else if (gameLogic.getState() == PLACING_BETS) {
            hitButton.isEnabled(false);
            standButton.isEnabled(false);
            doubleButton.isEnabled(false);
            if (money <= 0) {
                gameLogic.soundPlayer.playBankruptSounds();
                money = 1;
            }
        }else {
            money += gameLogic.ProcessRoundResults(bet);
            gameLogic.setState(PLACING_BETS);
            hasDoubled = false;
            bet = std::min(bet, money);
        }
        highMoney = std::max(highMoney, money);

        bet_placer.refresh(gameLogic.getState());

        while (std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>() ) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::Escape:
                        exit(0);
                    default:
                        break;
                }

            }

            hitButton.EventHandler(event, window);
            standButton.EventHandler(event, window);
            doubleButton.EventHandler(event, window);
            bet_placer.buttonsEventHandler(event, window);
        }
        //Game Refresh
        playersHandText.setString("Yours hand: " + std::to_string(players_hand.getSum()));
        croupiersHandText.setString("Croupiers hand: " + std::to_string(croupiers_hand.getSum()));
        scoreText.setString("Score: " + std::to_string(money));
        highScore.setString("High Score: " + std::to_string(highMoney));

        window.clear({20,20,20});
        //Background
        BG.draw(window);

        //Labels
        window.draw(playersHandText);
        window.draw(croupiersHandText);

        //Buttons
        hitButton.draw(window);
        standButton.draw(window);
        doubleButton.draw(window);

        //Hands
        players_hand.drawHand(window);
        croupiers_hand.drawHand(window);


        window.draw(scoreText);
        window.draw(highScore);

        bet_placer.draw(window);


        //Display
        window.display();
    }



    return 0;
}