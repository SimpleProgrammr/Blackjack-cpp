#include "SoundPlayer.h"
#include <filesystem>
#include <iostream>
#include <cstdlib>

namespace fs = std::filesystem;

static void loadSoundsFromDirectory(const std::string& dirPath, std::list<SoundPlayer::SOUND>& soundList) {
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        std::cerr << "Sound directory not found: " << dirPath << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (!entry.is_regular_file()) continue;

        const auto& path = entry.path();
        const std::string ext = path.extension().string();

        if (ext != ".wav" && ext != ".ogg" && ext != ".flac" && ext != ".mp3") continue;

        // emplace_back constructs SOUND in-place (avoids copy)
        soundList.emplace_back();
        auto& s = soundList.back();

        if (!s.buffer.loadFromFile(path.string())) {
            std::cerr << "Failed to load sound: " << path.string() << std::endl;
            soundList.pop_back();
            continue;
        }

        s.sound.setBuffer(s.buffer);
    }
}

SoundPlayer::SoundPlayer() {
    loadSoundsFromDirectory("./Assets/Sounds/win",      _winSounds);
    loadSoundsFromDirectory("./Assets/Sounds/lose",     _loseSounds);
    loadSoundsFromDirectory("./Assets/Sounds/tie",      _tieSounds);
    loadSoundsFromDirectory("./Assets/Sounds/bankrupt", _banSounds);

    if (!_bgMusic.buffer.loadFromFile("./Assets/Sounds/bg/casino-background-music.mp3")) {
        std::cerr << "Failed to load background music." << std::endl;
    } else {
        _bgMusic.sound.setBuffer(_bgMusic.buffer);

        _bgMusic.sound.setLooping(true);
    }
}

static void playRandomSound(std::list<SoundPlayer::SOUND>& soundList) {
    if (soundList.empty()) return;

    for (auto& s : soundList)
        s.sound.stop();

    int index = std::rand() % static_cast<int>(soundList.size());
    auto it = soundList.begin();
    std::advance(it, index);
    it->sound.play();
}

void SoundPlayer::playWinSounds() {
    playRandomSound(_winSounds);
}

void SoundPlayer::playLoseSounds() {
    playRandomSound(_loseSounds);
}

void SoundPlayer::playTieSounds() {
    playRandomSound(_tieSounds);
}

void SoundPlayer::playBankruptSounds() {
    playRandomSound(_banSounds);
}

void SoundPlayer::playBackgroundMusic() {
    // SFML 3.x: sf::Sound::Status::Playing (scoped enum)
    if (_bgMusic.sound.getStatus() != sf::Sound::Status::Playing) {
        _bgMusic.sound.setVolume(8.f);
        _bgMusic.sound.play();
    }
}
