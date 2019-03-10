#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
    FBullCowGame::Reset();
    return;
}

void FBullCowGame::Reset() {
    constexpr int CURENT_TRY = 1;
    constexpr int MAX_TRIES = 8;
    
    MyCurrentTry = CURENT_TRY;
    MyMaxTries = MAX_TRIES;
    return;
}

int FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

int FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

bool FBullCowGame::isGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) { 
    return true;
}
