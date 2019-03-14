/*
  The game logic (no view code or direct user interaction)
 the game is a simple word game based on Mastermind.
 */
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
    // does not change member vars
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    EGuessStatus CheckGuessValidity(FString) const;
    bool isGameWon() const;

    void Reset();

    FBullCowCount SubmitValidGuess(FString);
    
private:
    // see constructor for initialization
    bool BGameWon = false;
    int32 MyCurrentTry;
    FString MyHiddenWord;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};
