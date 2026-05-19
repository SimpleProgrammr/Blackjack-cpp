//
// Created by Michał on 14.05.2026.
//
#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Cursor.hpp>

#include "BasicButton.h"
#include "GameLogic.h"


class BetPlacer {
    long *_bet;
    sf::Vector2f _position;

    void _centerText() ;


public:
    sf::Text label;
    sf::RectangleShape borderShape;
    BasicButton increaseBetButton;
    BasicButton decreaseBetButton;
    BasicButton placeBetButton;

    BetPlacer(long* bet, sf::Font& font, sf::Vector2f position);

    void buttonsEventHandler(std::optional<sf::Event> event, sf::RenderWindow &window);
    void refresh(GAME_STATE gs);

    void draw(sf::RenderWindow &window);

};

