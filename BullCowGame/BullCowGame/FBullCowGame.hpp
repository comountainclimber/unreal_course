#pragma once

#include <string>

class FBullCowGame {
public:
    FBullCowGame();

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool isGameWon() const;
    
    void Reset(); // TODO mae a more rich return value
    bool CheckGuessValidity(std::string);
    
    // provide a method for counting
    // bulls and cow and increasing turn #

private:
    int MyCurrentTry;
    int MyMaxTries;
};
