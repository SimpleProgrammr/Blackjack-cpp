//
// Created by Michał on 03.05.2026.
//
#pragma once
#include <SFML/Graphics.hpp>

class BackgroundGen {
private:

    sf::Texture _texture;
    sf::Vector2f _scale = sf::Vector2f(1,1);
    sf::Vector2f _origin = sf::Vector2f(0,0);
    sf::Vector2f _position = sf::Vector2f(0,0);

public:
    BackgroundGen(const sf::Window &window,
                  const std::string &path,
                  const sf::Vector2f &origin = {0,0},
                  const sf::Vector2f &position= {0,0});


    sf::Vector2f getScale() const;
    sf::Vector2f getOrigin() const;
    sf::Vector2u getTextureDimensions() const;
    sf::Texture& getTexture();

    void setScale(const sf::Vector2f &scale);
    void setTexture(const sf::Texture &texture);
    void setOrigin(const sf::Vector2f &origin);
    void setPosition(const sf::Vector2f &position);

    void draw(sf::RenderWindow &window) const;
};
