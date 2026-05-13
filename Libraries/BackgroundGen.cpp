//
// Created by Michał on 03.05.2026.
//

#include "BackgroundGen.h"

#include "CustomErrors.h"

BackgroundGen::BackgroundGen(const sf::Window &window, const std::string &path, const sf::Vector2f &origin,
                             const sf::Vector2f &position) {

    if (!_texture.loadFromFile(path)) {
        throw FileNotFoundException(path);
    }

    _position = position;
    _origin = origin;

    _texture.setRepeated(true);
    _scale = {
        static_cast<float>(window.getSize().x) / _texture.getSize().x,
        static_cast<float>(window.getSize().y) / _texture.getSize().y
    };

}

sf::Vector2f BackgroundGen::getScale() const {
    return _scale;
}

sf::Vector2f BackgroundGen::getOrigin() const {
    return _origin;
}

sf::Vector2u BackgroundGen::getTextureDimensions() const {
    return _texture.getSize();
}


sf::Texture & BackgroundGen::getTexture() {
    return _texture;
}

void BackgroundGen::setScale(const sf::Vector2f &scale) {
    _scale = scale;
}

void BackgroundGen::setTexture(const sf::Texture &texture) {
    _texture = texture;
}

void BackgroundGen::setOrigin(const sf::Vector2f &origin) {
    _origin = origin;
}

void BackgroundGen::setPosition(const sf::Vector2f &position) {
    _position = position;
}

void BackgroundGen::draw(sf::RenderWindow &window) const {
    sf::Sprite sprite(_texture);

    sprite.setScale(_scale);

    sprite.setOrigin(_origin);
    sprite.setPosition(_position);

    window.draw(sprite);

}

