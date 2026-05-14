//
// Created by Michał on 13.05.2026.
//

#include "GameLogic.h"

void GameLogic::HitMe(PlayersHand &players, PlayersHand &croupiers) {
    players.addNewRandomCard(1);
    if (players.getSum() > 21) {
        _state = Stand(players, croupiers);
        return;
    }
    _state =  IN_PROGRESS;
}

void GameLogic::DoubleMe(PlayersHand &players, PlayersHand &croupiers, long &Bet) {
    Bet *= 2;
    players.addNewRandomCard(1);
    if (players.getSum() > 21) {
        _state = Stand(players, croupiers);
        return;
    }
    _state =  Stand(players, croupiers);
}

GAME_STATE GameLogic::Stand(PlayersHand &players, PlayersHand &croupiers) {
    if (players.getSum() > 21) {
        _state = LOST;
        return _state;
    }

    croupiers.flipLastCard();

    while (croupiers.getSum() < 17) {
        croupiers.addNewRandomCard(1);
    }

    if  (players.getSum() == 21 && players.getCardAmount() == 2) {
        _state = BLACKJACK;
    }
    else if  (croupiers.getSum() > 21) {
        _state = WON;
    }
    else if  (croupiers.getSum() < players.getSum()) {
        _state = WON;
    }
    else if (croupiers.getSum() == players.getSum()) {
        _state = TIE;
    }
    else
        _state =  LOST;
    return _state;
}

void GameLogic::PlaceBet(PlayersHand &players, PlayersHand &croupiers) {
    players.clear();
    croupiers.clear();

    croupiers.addNewRandomCard(2);
    croupiers.flipLastCard();

    players.addNewRandomCard(2);

    _state = IN_PROGRESS;
}

GAME_STATE GameLogic::getState() const {
    return _state;
}

void GameLogic::setState(const GAME_STATE state) {
    _state = state;
}

long GameLogic::ProcessRoundResults(long bet)  {
    switch (_state) {
        case WON:
            soundPlayer.playWinSounds();
            return 2*bet;
        case LOST:
            soundPlayer.playLoseSounds();
            return 0;
        case TIE:
            soundPlayer.playTieSounds();
            return bet;
        case BLACKJACK:
            soundPlayer.playWinSounds();
            return 2.5 * bet;
        default:
            return 0;
    }
}
