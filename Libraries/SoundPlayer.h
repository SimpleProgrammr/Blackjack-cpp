#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SoundPlayer {
public:
    struct SOUND {
        sf::SoundBuffer buffer;
        sf::Sound sound;

        SOUND() : sound(buffer) {}

        // sf::SoundBuffer and sf::Sound are not copyable in SFML 3 — provide move only
        SOUND(const SOUND&) = delete;
        SOUND& operator=(const SOUND&) = delete;

        SOUND(SOUND&& other) noexcept
            : buffer(std::move(other.buffer))
            , sound(buffer)             // rebind to our new buffer
        {}

        SOUND& operator=(SOUND&& other) noexcept {
            if (this != &other) {
                buffer = std::move(other.buffer);
                sound  = sf::Sound(buffer); // rebind
            }
            return *this;
        }
    };

private:
    std::list<SOUND> _winSounds;
    std::list<SOUND> _loseSounds;
    std::list<SOUND> _tieSounds;
    std::list<SOUND> _banSounds;
    SOUND _bgMusic;

public:
    SoundPlayer();

    void playWinSounds();
    void playLoseSounds();
    void playTieSounds();
    void playBankruptSounds();
    void playBackgroundMusic();
};