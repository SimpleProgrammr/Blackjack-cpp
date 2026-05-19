//
// Created by Michał on 13.05.2026.
//

#include "PlayersHand.h"

#include <algorithm>
#include <random>

void PlayersHand::_alignCardsToCenter() {

    if (_playingCards.empty()) {
        return;
    }

    const float card_width = _playingCards[0]->getSize().x;
    const int n_elements = _playingCards.size()-1;

    while (n_elements * card_width + n_elements * _spacer_width > _border_size.x) {
        _spacer_width *= 0.99f;
    }

    float base_offset = (_border_size.x - (n_elements) * card_width - (n_elements) * _spacer_width)/2;
    const float border_right_side = _position.x - _border_size.x/2;


    for (auto& card : _playingCards) {
        const sf::Vector2f new_pos = {(border_right_side+base_offset) ,_position.y};
        card->setPosition(new_pos);

        base_offset += card_width + _spacer_width;
    }
}

PlayersHand::PlayersHand(const sf::RenderWindow &window) {
    _playingCards = std::vector<std::shared_ptr<PlayingCard>>();
    _border_size = sf::Vector2f(window.getSize().x, window.getSize().y/5);
}

void PlayersHand::addNewRandomCard(const int amount) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 51);

    for (int i = 0; i < amount; i++) {
        auto random_type = static_cast<CARD_TYPE>(dist(gen));

        auto new_card = std::make_shared<PlayingCard>(random_type);
        new_card->centerOrigin();
        new_card->setScale(_card_scale);

        _playingCards.push_back(new_card);
    }
    _alignCardsToCenter();
}

void PlayersHand::clear() {
    _playingCards.clear();
}

int PlayersHand::getSum() {
    _sum = 0;
    _alt_sum = 0;
    for (const auto& card : _playingCards) {
        if (card->isHidden())
            continue;
        int val = card->getValue();
        _sum += val;
        _alt_sum += val;
        if (card->getName() == "ace") {
            _alt_sum -= 10;
        }
    }
    if (_sum > 21) {
        return _alt_sum;
    }
    return _sum;
}

PlayingCard& PlayersHand::getLastCard() const {
    return *_playingCards.back();
}

void PlayersHand::drawHand(sf::RenderWindow &window) const {
    for (auto const& card : _playingCards) {
        card->draw(window);
    }
}

void PlayersHand::setPosition(const sf::Vector2f position) {
    _position = position;
    _alignCardsToCenter();
}

sf::Vector2f PlayersHand::getPosition() const {
    return _position;
}

void PlayersHand::setSpacerWidth(const float spacerWidth) {
    _spacer_width = spacerWidth;
    _alignCardsToCenter();
}

float PlayersHand::getSpacerWidth() const {
    return _spacer_width;
}

void PlayersHand::setCardsScale(const sf::Vector2f scale) {
    _card_scale = scale;
    for (const auto& card : _playingCards) {
        card->setScale(_card_scale);
    }
    _alignCardsToCenter();
}

sf::Vector2f PlayersHand::getCardsScale() const {
    return _card_scale;
}

void PlayersHand::flipLastCard() const {
    _playingCards.back()->flip();
}

int PlayersHand::getCardAmount() const {
    return _playingCards.size();
}
