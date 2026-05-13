//
// Created by Michał on 03.05.2026.
//
#pragma once

#include <functional>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>


class BasicButton {
private:
    bool _enabled = true;
    std::function<void()> _onClick;

    sf::Vector2f _size = {150,80};
    sf::Vector2f _position = {0,0};
    sf::RectangleShape _shape;

    sf::Vector2f _label_position = _position + _size/2.f;
    sf::Color _label_color = sf::Color::Black;
    sf::Text _label;
    sf::Font _font;

    int _border_radius = 0;
    sf::Color _border_color = sf::Color::Black;

    sf::Color _base_color = {255, 144, 0};

    sf::Color _hover_color = {179,101,0};

    sf::Color _click_color = {120,67,0};

    void centerText(sf::Text &text);

public:
    BasicButton(sf::Vector2f size, sf::Vector2f position, std::function<void()> onClick, const sf::Text &text);

    void draw(sf::RenderWindow &window) const;
    void EventHandler(std::optional<sf::Event> event, sf::RenderWindow& window);

    void setOnClick(std::function<void()> callback);

    void setLabelText(std::string label);
    void setLabelFontSize(unsigned int size);
    void setLabelColor(sf::Color color);
    void setLabelPosition(sf::Vector2f position);

    void setBorderRadius(int radius);
    void setBorderColor(sf::Color color);

    void setBaseColor(sf::Color color);

    void setHoverColor(sf::Color color);

    void setClickColor(sf::Color color);

    void setPosition(sf::Vector2f position);

    bool isEnabled() const;
    void isEnabled(bool value);

};