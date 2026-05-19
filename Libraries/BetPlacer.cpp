//
// Created by Michał on 14.05.2026.
//

#include "BetPlacer.h"

void BetPlacer::_centerText() {

    const sf::FloatRect labelBounds = label.getLocalBounds();
    const sf::FloatRect boxBounds = borderShape.getLocalBounds();
    label.setOrigin({
        labelBounds.position.x + labelBounds.size.x / 2.f,
        labelBounds.position.y + labelBounds.size.y / 2.f
    });

    label.setPosition(borderShape.getPosition());
}

BetPlacer::BetPlacer(long* bet, sf::Font& font, sf::Vector2f position) :
    _bet(bet),
    _position(position),
    label(font, std::to_string(*bet)),
    increaseBetButton(BasicButton({40, 40}, {_position.x + 75, _position.y}, []() {}, sf::Text(font, "+"))),
    decreaseBetButton(BasicButton({40, 40}, {_position.x - 75, _position.y}, []() {}, sf::Text(font, "-"))),
    placeBetButton(BasicButton({200, 25}, {_position.x, _position.y+40}, []() {}, sf::Text(font, "Place Your Bet",20))) {

    borderShape = sf::RectangleShape({80, 40});
    borderShape.setOrigin(borderShape.getLocalBounds().size / 2.f);
    borderShape.setPosition(_position);
    borderShape.setFillColor({60,60,60});
    borderShape.setOutlineColor(sf::Color::Black);
    borderShape.setOutlineThickness(2);

    _centerText();
    // label.setOrigin(borderShape.getLocalBounds().size / 2.f);
    // label.setPosition(_position);

    increaseBetButton.centerOrigin();
    increaseBetButton.setBorderRadius(2);
    decreaseBetButton.centerOrigin();
    decreaseBetButton.setBorderRadius(2);
    placeBetButton.centerOrigin();
    placeBetButton.setBorderRadius(2);
}

void BetPlacer::buttonsEventHandler( std::optional<sf::Event> event, sf::RenderWindow &window) {
    increaseBetButton.EventHandler(event, window);
    decreaseBetButton.EventHandler(event, window);
    placeBetButton.EventHandler(event, window);
}

void BetPlacer::refresh(GAME_STATE gs) {
    if (gs != PLACING_BETS) {
        increaseBetButton.isEnabled(false);
        decreaseBetButton.isEnabled(false);
        placeBetButton.isEnabled(false);
    }
    else {
        increaseBetButton.isEnabled(true);
        decreaseBetButton.isEnabled(true);
        placeBetButton.isEnabled(true);
    }
    label.setString(std::to_string(*_bet));
}

void BetPlacer::draw(sf::RenderWindow &window) {
    _centerText();
    window.draw(borderShape);
    window.draw(label);
    increaseBetButton.draw(window);
    decreaseBetButton.draw(window);
    placeBetButton.draw(window);
}
