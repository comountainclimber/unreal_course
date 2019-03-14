#include "FBullCowGame.hpp"
#include <string>
#include <map>
#define TMap std::map

using int32 = int;
using FString = std::string;

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

int32 FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

bool FBullCowGame::isGameWon() const {
    return BGameWon;
}

int32 FBullCowGame::GetHiddenWordLength() const {
    return MyHiddenWord.length();
}

FBullCowGame::FBullCowGame() {
    FBullCowGame::Reset();
    return;
}

bool FBullCowGame::IsIsogram(FString Word) const {
    if (Word.length() <= 1 ) return true;
    TMap<char, bool> LettersSeen;
    // auto keyword allows the compiler to determine
    // the type in the iterator
    for (auto Letter : Word) {
        Letter = tolower(Letter);
        if (LettersSeen[Letter]) return false;
        LettersSeen[Letter] = true;
    }
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
    for (auto Letter : Word) {
        bool IsLowercase = islower(Letter);
        if (!IsLowercase) return IsLowercase;
    }
    return true;
}

void FBullCowGame::Reset() {
    constexpr int CURENT_TRY = 1;
    constexpr int MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = CURENT_TRY;
    MyMaxTries = MAX_TRIES;
    BGameWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!IsIsogram(Guess)) {
        return EGuessStatus::Not_Isogram;
    } else if (!IsLowercase(Guess)) {
        return EGuessStatus::Not_Lowercase;
    } else if (Guess.length() != GetHiddenWordLength()) {
        return EGuessStatus::Wrong_Length;
    }
    return EGuessStatus::OK;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length();

    for (int32 i = 0; i < WordLength; i++) {
        for (int32 j = 0; j < WordLength; j++) {
            if (Guess[j] == MyHiddenWord[i]) {
                if (i == j) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    if (BullCowCount.Bulls == WordLength) {
        BGameWon = true;
    }

    return BullCowCount;
}
