//
// Created by Michał on 12.05.2026.
//
#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

enum CARD_TYPE {
    CLUBS_2,
    CLUBS_3,
    CLUBS_4,
    CLUBS_5,
    CLUBS_6,
    CLUBS_7,
    CLUBS_8,
    CLUBS_9,
    CLUBS_10,
    CLUBS_JACK,
    CLUBS_KING,
    CLUBS_QUEEN,
    CLUBS_ACE,

    DIAMONDS_2,
    DIAMONDS_3,
    DIAMONDS_4,
    DIAMONDS_5,
    DIAMONDS_6,
    DIAMONDS_7,
    DIAMONDS_8,
    DIAMONDS_9,
    DIAMONDS_10,
    DIAMONDS_JACK,
    DIAMONDS_KING,
    DIAMONDS_QUEEN,
    DIAMONDS_ACE,

    HEARTS_2,
    HEARTS_3,
    HEARTS_4,
    HEARTS_5,
    HEARTS_6,
    HEARTS_7,
    HEARTS_8,
    HEARTS_9,
    HEARTS_10,
    HEARTS_JACK,
    HEARTS_KING,
    HEARTS_QUEEN,
    HEARTS_ACE,

    SPADES_2,
    SPADES_3,
    SPADES_4,
    SPADES_5,
    SPADES_6,
    SPADES_7,
    SPADES_8,
    SPADES_9,
    SPADES_10,
    SPADES_JACK,
    SPADES_KING,
    SPADES_QUEEN,
    SPADES_ACE,

    CARD_BACK
};


class PlayingCard {
private:
    const CARD_TYPE _cardType;
    bool _hidden = false;
    sf::String _name;
    sf::String _sign;
    int _value;
    sf::Texture _texture;
    sf::Sprite _card;

    static sf::Texture _TextureGen(CARD_TYPE cardType);
    static std::pair<sf::String, sf::String> _unpackTextName(CARD_TYPE cardType);
    static int _resolveValue(CARD_TYPE cardType);

    sf::Sprite _ShapeGen(CARD_TYPE cardType) const;

public:
    explicit PlayingCard(CARD_TYPE card);

    int getValue() const;

    void hide();
    void unHide();
    void flip();
    bool isHidden() const;

    void setPosition(const sf::Vector2f position);
    void setOrigin(const sf::Vector2f origin);
    void centerOrigin();
    void setRotation(const sf::Angle rotation);
    void setScale(const sf::Vector2f scale);

    sf::Vector2f getOrigin() const;
    sf::Vector2f getPosition() const;
    sf::Angle getRotation() const;
    sf::Vector2f getScale() const;


    sf::String getName();
    sf::String getSign();

    sf::Vector2f getSize() const;

    void draw(sf::RenderWindow& window) const;

};

