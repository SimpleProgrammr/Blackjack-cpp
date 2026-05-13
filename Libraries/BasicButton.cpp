//
// Created by Michał on 03.05.2026.
//

#include "BasicButton.h"

#include <utility>

#include "CustomErrors.h"

void BasicButton::centerText(sf::Text &text) {
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    text.setPosition({
        _position.x + _size.x / 2.f,
        _position.y + _size.y / 2.f
    });
}

BasicButton::BasicButton(const sf::Vector2f size, const sf::Vector2f position, std::function<void()> onClick, const sf::Text &text): _label(text) {
    _onClick = std::move(onClick);
    _size = size;
    _position = position;

    _shape = sf::RectangleShape(size);
    _shape.setPosition(_position);
    _shape.setFillColor(_base_color);
    _shape.setOutlineThickness(_border_radius);
    _shape.setOutlineColor(_border_color);


    centerText(_label);
}

void BasicButton::draw(sf::RenderWindow &window) const {
    window.draw(_shape);
    window.draw(_label);

}

void BasicButton::EventHandler(std::optional<sf::Event> event, sf::RenderWindow &window) {
    if (!_enabled)
        return;

    const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    bool hovered = _shape.getGlobalBounds().contains(mousePos);

    if (event->is<sf::Event::MouseMoved>()) {
        _shape.setFillColor(hovered ? _hover_color : _base_color);
    }
    if (auto* keyStroke = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (keyStroke->button == sf::Mouse::Button::Left && hovered) {
            _shape.setFillColor(_click_color);
        }
    }
    if (auto* keyStroke = event->getIf<sf::Event::MouseButtonReleased>()) {
        if (keyStroke->button == sf::Mouse::Button::Left && hovered) {
            _shape.setFillColor(_hover_color);
            if (_onClick)
                _onClick();
        }
    }
}

void BasicButton::setOnClick(std::function<void()> callback) {
    _onClick = std::move(callback);
}

void BasicButton::setLabelText(std::string label) {
    _label.setString(label);
}

void BasicButton::setLabelFontSize(const unsigned int size) {
    _label.setCharacterSize(size);
}

void BasicButton::setLabelColor(sf::Color color) {
    _label_color = color;
    _label.setFillColor(color);
}

void BasicButton::setLabelPosition(sf::Vector2f position) {
    _label_position = position;
}

void BasicButton::setBorderRadius(int radius) {
    _border_radius = radius;
    _shape.setOutlineThickness(_border_radius);
}

void BasicButton::setBorderColor(sf::Color color) {
    _border_color = color;
    _shape.setOutlineColor(_border_color);
}

void BasicButton::setBaseColor(sf::Color color) {
    _base_color = color;
    _shape.setFillColor(_base_color);
}

void BasicButton::setHoverColor(sf::Color color) {
    _base_color = color;
}

void BasicButton::setClickColor(sf::Color color) {
    _click_color = color;
}

void BasicButton::setPosition(sf::Vector2f position) {
    _position = position;
    centerText(_label);
}

bool BasicButton::isEnabled() const {
    return _enabled;
}

void BasicButton::isEnabled(bool value) {
    if (value) {
        _enabled = true;
        _shape.setFillColor(_base_color);
        _label.setFillColor(_label_color);

    }
    else {
        _enabled = false;
        _shape.setFillColor({50,50,50, 127});
        auto label_color = _shape.getFillColor();
        label_color.a = 127;
        _label.setFillColor(label_color);
    }
};
