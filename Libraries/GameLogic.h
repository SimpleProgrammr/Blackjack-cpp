//
// Created by Michał on 13.05.2026.
//
#pragma once
#include "PlayersHand.h"
#include "SoundPlayer.h"

enum GAME_STATE {
    LOST,
    WON,
    BLACKJACK,
    TIE,
    IN_PROGRESS,
    PLACING_BETS
};

class GameLogic {
    GAME_STATE _state = PLACING_BETS;


public:
    SoundPlayer soundPlayer;
    GameLogic() {
        soundPlayer = SoundPlayer();
        soundPlayer.playBackgroundMusic();
    };

    void HitMe(PlayersHand& players, PlayersHand& croupiers);
    void DoubleMe(PlayersHand& players, PlayersHand& croupiers, long& Bet);
    GAME_STATE Stand(PlayersHand& players, PlayersHand& croupiers);

    void PlaceBet(PlayersHand& players, PlayersHand& croupiers);
    GAME_STATE getState() const;
    void setState(GAME_STATE state) ;

    long ProcessRoundResults(long bet) ;
};

