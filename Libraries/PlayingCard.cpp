//
// Created by Michał on 12.05.2026.
//

#include "PlayingCard.h"
#include "CustomErrors.h"


sf::Texture PlayingCard::_TextureGen(CARD_TYPE cardType) {
    sf::Texture texture;
    std::filesystem::path path = "";
    switch (cardType) {
        case CLUBS_2: path = R"(./Assets/CardsTextures/clubs-2.png)"; break;
        case CLUBS_3: path = R"(./Assets/CardsTextures/clubs-3.png)"; break;
        case CLUBS_4: path = R"(./Assets/CardsTextures/clubs-4.png)"; break;
        case CLUBS_5: path = R"(./Assets/CardsTextures/clubs-5.png)"; break;
        case CLUBS_6: path = R"(./Assets/CardsTextures/clubs-6.png)"; break;
        case CLUBS_7: path = R"(./Assets/CardsTextures/clubs-7.png)"; break;
        case CLUBS_8: path = R"(./Assets/CardsTextures/clubs-8.png)"; break;
        case CLUBS_9: path = R"(./Assets/CardsTextures/clubs-9.png)"; break;
        case CLUBS_10: path = R"(./Assets/CardsTextures/clubs-10.png)"; break;
        case CLUBS_JACK: path = R"(./Assets/CardsTextures/clubs-jack.png)"; break;
        case CLUBS_KING: path = R"(./Assets/CardsTextures/clubs-king.png)"; break;
        case CLUBS_QUEEN: path = R"(./Assets/CardsTextures/clubs-queen.png)"; break;
        case CLUBS_ACE: path = R"(./Assets/CardsTextures/clubs-ace.png)"; break;

        case DIAMONDS_2: path = R"(./Assets/CardsTextures/diamonds-2.png)"; break;
        case DIAMONDS_3: path = R"(./Assets/CardsTextures/diamonds-3.png)"; break;
        case DIAMONDS_4: path = R"(./Assets/CardsTextures/diamonds-4.png)"; break;
        case DIAMONDS_5: path = R"(./Assets/CardsTextures/diamonds-5.png)"; break;
        case DIAMONDS_6: path = R"(./Assets/CardsTextures/diamonds-6.png)"; break;
        case DIAMONDS_7: path = R"(./Assets/CardsTextures/diamonds-7.png)"; break;
        case DIAMONDS_8: path = R"(./Assets/CardsTextures/diamonds-8.png)"; break;
        case DIAMONDS_9: path = R"(./Assets/CardsTextures/diamonds-9.png)"; break;
        case DIAMONDS_10: path = R"(./Assets/CardsTextures/diamonds-10.png)"; break;
        case DIAMONDS_JACK: path = R"(./Assets/CardsTextures/diamonds-jack.png)"; break;
        case DIAMONDS_KING: path = R"(./Assets/CardsTextures/diamonds-king.png)"; break;
        case DIAMONDS_QUEEN: path = R"(./Assets/CardsTextures/diamonds-queen.png)"; break;
        case DIAMONDS_ACE: path = R"(./Assets/CardsTextures/diamonds-ace.png)"; break;

        case HEARTS_2: path = R"(./Assets/CardsTextures/hearts-2.png)"; break;
        case HEARTS_3: path = R"(./Assets/CardsTextures/hearts-3.png)"; break;
        case HEARTS_4: path = R"(./Assets/CardsTextures/hearts-4.png)"; break;
        case HEARTS_5: path = R"(./Assets/CardsTextures/hearts-5.png)"; break;
        case HEARTS_6: path = R"(./Assets/CardsTextures/hearts-6.png)"; break;
        case HEARTS_7: path = R"(./Assets/CardsTextures/hearts-7.png)"; break;
        case HEARTS_8: path = R"(./Assets/CardsTextures/hearts-8.png)"; break;
        case HEARTS_9: path = R"(./Assets/CardsTextures/hearts-9.png)"; break;
        case HEARTS_10: path = R"(./Assets/CardsTextures/hearts-10.png)"; break;
        case HEARTS_JACK: path = R"(./Assets/CardsTextures/hearts-jack.png)"; break;
        case HEARTS_KING: path = R"(./Assets/CardsTextures/hearts-king.png)"; break;
        case HEARTS_QUEEN: path = R"(./Assets/CardsTextures/hearts-queen.png)"; break;
        case HEARTS_ACE: path = R"(./Assets/CardsTextures/hearts-ace.png)"; break;

        case SPADES_2: path = R"(./Assets/CardsTextures/spades-2.png)"; break;
        case SPADES_3: path = R"(./Assets/CardsTextures/spades-3.png)"; break;
        case SPADES_4: path = R"(./Assets/CardsTextures/spades-4.png)"; break;
        case SPADES_5: path = R"(./Assets/CardsTextures/spades-5.png)"; break;
        case SPADES_6: path = R"(./Assets/CardsTextures/spades-6.png)"; break;
        case SPADES_7: path = R"(./Assets/CardsTextures/spades-7.png)"; break;
        case SPADES_8: path = R"(./Assets/CardsTextures/spades-8.png)"; break;
        case SPADES_9: path = R"(./Assets/CardsTextures/spades-9.png)"; break;
        case SPADES_10: path = R"(./Assets/CardsTextures/spades-10.png)"; break;
        case SPADES_JACK: path = R"(./Assets/CardsTextures/spades-jack.png)"; break;
        case SPADES_KING: path = R"(./Assets/CardsTextures/spades-king.png)"; break;
        case SPADES_QUEEN: path = R"(./Assets/CardsTextures/spades-queen.png)"; break;
        case SPADES_ACE: path = R"(./Assets/CardsTextures/spades-ace.png)"; break;

        case CARD_BACK: path = R"(./Assets/CardsTextures/card-back.png)";
    }

    if (!texture.loadFromFile(path)) {
        throw FileNotFoundException(path.generic_string());
    }
    return texture;
}

sf::Sprite PlayingCard::_ShapeGen(CARD_TYPE cardType) const {
    sf::Sprite sprite(_texture);
    return sprite;
}

std::pair<sf::String, sf::String> PlayingCard::_unpackTextName(CARD_TYPE cardType) {

    sf::String name, sign;

    switch (cardType) {
        case CLUBS_2: sign = "clubs"; name = "2"; break;
        case CLUBS_3: sign = "clubs"; name = "3"; break;
        case CLUBS_4: sign = "clubs"; name = "4"; break;
        case CLUBS_5: sign = "clubs"; name = "5"; break;
        case CLUBS_6: sign = "clubs"; name = "6"; break;
        case CLUBS_7: sign = "clubs"; name = "7"; break;
        case CLUBS_8: sign = "clubs"; name = "8"; break;
        case CLUBS_9: sign = "clubs"; name = "9"; break;
        case CLUBS_10: sign = "clubs"; name = "10"; break;
        case CLUBS_JACK: sign = "clubs"; name = "jack"; break;
        case CLUBS_KING: sign = "clubs"; name = "king"; break;
        case CLUBS_QUEEN: sign = "clubs"; name = "queen"; break;
        case CLUBS_ACE: sign = "clubs"; name = "ace"; break;

        case DIAMONDS_2: sign = "diamonds"; name = "2"; break;
        case DIAMONDS_3: sign = "diamonds"; name = "3"; break;
        case DIAMONDS_4: sign = "diamonds"; name = "4"; break;
        case DIAMONDS_5: sign = "diamonds"; name = "5"; break;
        case DIAMONDS_6: sign = "diamonds"; name = "6"; break;
        case DIAMONDS_7: sign = "diamonds"; name = "7"; break;
        case DIAMONDS_8: sign = "diamonds"; name = "8"; break;
        case DIAMONDS_9: sign = "diamonds"; name = "9"; break;
        case DIAMONDS_10: sign = "diamonds"; name = "10"; break;
        case DIAMONDS_JACK: sign = "diamonds"; name = "jack"; break;
        case DIAMONDS_KING: sign = "diamonds"; name = "king"; break;
        case DIAMONDS_QUEEN: sign = "diamonds"; name = "queen"; break;
        case DIAMONDS_ACE: sign = "diamonds"; name = "ace"; break;

        case HEARTS_2: sign = "hearts"; name = "2"; break;
        case HEARTS_3: sign = "hearts"; name = "3"; break;
        case HEARTS_4: sign = "hearts"; name = "4"; break;
        case HEARTS_5: sign = "hearts"; name = "5"; break;
        case HEARTS_6: sign = "hearts"; name = "6"; break;
        case HEARTS_7: sign = "hearts"; name = "7"; break;
        case HEARTS_8: sign = "hearts"; name = "8"; break;
        case HEARTS_9: sign = "hearts"; name = "9"; break;
        case HEARTS_10: sign = "hearts"; name = "10"; break;
        case HEARTS_JACK: sign = "hearts"; name = "jack"; break;
        case HEARTS_KING: sign = "hearts"; name = "king"; break;
        case HEARTS_QUEEN: sign = "hearts"; name = "queen"; break;
        case HEARTS_ACE: sign = "hearts"; name = "ace"; break;

        case SPADES_2: sign = "spades"; name = "2"; break;
        case SPADES_3: sign = "spades"; name = "3"; break;
        case SPADES_4: sign = "spades"; name = "4"; break;
        case SPADES_5: sign = "spades"; name = "5"; break;
        case SPADES_6: sign = "spades"; name = "6"; break;
        case SPADES_7: sign = "spades"; name = "7"; break;
        case SPADES_8: sign = "spades"; name = "8"; break;
        case SPADES_9: sign = "spades"; name = "9"; break;
        case SPADES_10: sign = "spades"; name = "10"; break;
        case SPADES_JACK: sign = "spades"; name = "jack"; break;
        case SPADES_KING: sign = "spades"; name = "king"; break;
        case SPADES_QUEEN: sign = "spades"; name = "queen"; break;
        case SPADES_ACE: sign = "spades"; name = "ace"; break;
        case CARD_BACK:
            break;
    }

    return std::pair(sign, name);

}

int PlayingCard::_resolveValue(const CARD_TYPE cardType) {
    int val = 0;

    switch (cardType) {
        case CLUBS_2: val = 2; break;
        case CLUBS_3: val = 3; break;
        case CLUBS_4: val = 4; break;
        case CLUBS_5: val = 5; break;
        case CLUBS_6: val = 6; break;
        case CLUBS_7: val = 7; break;
        case CLUBS_8: val = 8; break;
        case CLUBS_9: val = 9; break;
        case CLUBS_10: val = 10; break;
        case CLUBS_JACK: val = 10; break;
        case CLUBS_KING: val = 10; break;
        case CLUBS_QUEEN: val = 10; break;
        case CLUBS_ACE: val = 11; break;

        case DIAMONDS_2: val = 2; break;
        case DIAMONDS_3: val = 3; break;
        case DIAMONDS_4: val = 4; break;
        case DIAMONDS_5: val = 5; break;
        case DIAMONDS_6: val = 6; break;
        case DIAMONDS_7: val = 7; break;
        case DIAMONDS_8: val = 8; break;
        case DIAMONDS_9: val = 9; break;
        case DIAMONDS_10: val = 10; break;
        case DIAMONDS_JACK: val = 10; break;
        case DIAMONDS_KING: val = 10; break;
        case DIAMONDS_QUEEN: val = 10; break;
        case DIAMONDS_ACE: val = 11; break;

        case HEARTS_2: val = 2; break;
        case HEARTS_3: val = 3; break;
        case HEARTS_4: val = 4; break;
        case HEARTS_5: val = 5; break;
        case HEARTS_6: val = 6; break;
        case HEARTS_7: val = 7; break;
        case HEARTS_8: val = 8; break;
        case HEARTS_9: val = 9; break;
        case HEARTS_10: val = 10; break;
        case HEARTS_JACK: val = 10; break;
        case HEARTS_KING: val = 10; break;
        case HEARTS_QUEEN: val = 10; break;
        case HEARTS_ACE: val = 11; break;

        case SPADES_2: val = 2; break;
        case SPADES_3: val = 3; break;
        case SPADES_4: val = 4; break;
        case SPADES_5: val = 5; break;
        case SPADES_6: val = 6; break;
        case SPADES_7: val = 7; break;
        case SPADES_8: val = 8; break;
        case SPADES_9: val = 9; break;
        case SPADES_10: val = 10; break;
        case SPADES_JACK: val = 10; break;
        case SPADES_KING: val = 10; break;
        case SPADES_QUEEN: val = 10; break;
        case SPADES_ACE: val = 11; break;
        default: ;
    }

    return val;
}



PlayingCard::PlayingCard(const CARD_TYPE card) : _cardType(card), _value(0), _texture(_TextureGen(card)), _card(_ShapeGen(card)) {
    auto [sign, name] = _unpackTextName(card);
    _name = name;
    _sign = sign;
    _value = _resolveValue(_cardType);
}

int PlayingCard::getValue() const {
    return _value;
}

void PlayingCard::hide() {
    _hidden = true;

    _texture = _TextureGen(CARD_BACK);
    _card.setTexture(_texture);
}

void PlayingCard::unHide() {
    _hidden = false;

    _texture = _TextureGen(_cardType);
    _card.setTexture(_texture);
}

void PlayingCard::flip() {
    if (_hidden)
        unHide();
    else
        hide();
}

bool PlayingCard::isHidden() const {
    return _hidden;
}


void PlayingCard::setPosition(const sf::Vector2f position) {
    _card.setPosition(position);
}

void PlayingCard::setOrigin(const sf::Vector2f origin) {
    _card.setOrigin(origin);
}

void PlayingCard::centerOrigin() {
    auto locB = _card.getLocalBounds();
    _card.setOrigin({locB.size/2.f});
}

void PlayingCard::setRotation(const sf::Angle rotation) {
    return _card.setRotation(rotation);
}

void PlayingCard::setScale(const sf::Vector2f scale) {
    _card.setScale(scale);
}


sf::Vector2f PlayingCard::getOrigin() const {
    return _card.getOrigin();
}

sf::Vector2f PlayingCard::getPosition() const {
    return _card.getPosition();
}

sf::Angle PlayingCard::getRotation() const {
    return _card.getRotation();
}

sf::Vector2f PlayingCard::getScale() const {
    return _card.getScale();
}

sf::String PlayingCard::getName() {
    return _name;
}

sf::String PlayingCard::getSign() {
    return _sign;
}

sf::Vector2f operator*(const sf::Vector2u & lhs, const sf::Vector2f & rhs) {
    float x = lhs.x * rhs.x;
    float y = lhs.y * rhs.y;

    return sf::Vector2f(x, y);
}

sf::Vector2f PlayingCard::getSize() const {
    return _card.getTexture().getSize() * _card.getScale();
}

void PlayingCard::draw(sf::RenderWindow& window) const {
    window.draw(_card);
};

