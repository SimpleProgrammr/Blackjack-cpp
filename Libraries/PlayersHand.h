//
// Created by Michał on 13.05.2026.
//
#pragma once

#include "PlayingCard.h"

class PlayersHand {
private:
    std::vector<std::shared_ptr<PlayingCard>> _playingCards;
    int _sum = 0;
    int _alt_sum = 0;

    sf::Vector2f _position = {0.0f, 0.0f};
    sf::Vector2f _border_size;
    float _spacer_width = -35.f;
    sf::Vector2f _card_scale = {0.33f,0.33f};

    void _alignCardsToCenter() const;

public:
    explicit PlayersHand(const sf::RenderWindow &window);

    void addNewRandomCard(int amount);
    void clear();

    int getSum();

    PlayingCard& getLastCard() const;

    void drawHand(sf::RenderWindow &window) const;

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    void setSpacerWidth(float spacerWidth);
    float getSpacerWidth() const;

    void setCardsScale(sf::Vector2f scale);
    sf::Vector2f getCardsScale() const;

    void flipLastCard() const;
    int getCardAmount() const;
};

