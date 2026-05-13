//
// Created by Michał on 13.05.2026.
//
#pragma once
#include "PlayersHand.h"

enum GAME_STATE {
    LOST,
    WON,
    BLACKJACK,
    TIE,
    IN_PROGRESS,
    PLACING_BETS
};

class GameLogic {
    GAME_STATE _state = IN_PROGRESS;

public:
    GameLogic(){};

    void HitMe(PlayersHand& players, PlayersHand& croupiers);
    void DoubleMe(PlayersHand& players, PlayersHand& croupiers, long& Bet);
    GAME_STATE Stand(PlayersHand& players, PlayersHand& croupiers);

    void PlaceBet(PlayersHand& players, PlayersHand& croupiers, long& Bet);
    GAME_STATE getState() const;
};

