#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Length
};

class FBullCowGame {
public:
    FBullCowGame();

    // type function const indicates a read only getter
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    EGuessStatus CheckGuessValidity(FString) const;
    bool isGameWon() const;

    void Reset(); // TODO mae a more rich return value

    FBullCowCount SubmitValidGuess(FString);
    
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool BGameWon = false;
};
