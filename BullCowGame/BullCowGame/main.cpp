/*
 This is the console executable that makes use of our
 BullCow class - this acts as the view in a MVC pattern
 and is responsible for all user interactions. For game
 logic see the FBullCowGame class
 */
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// to make syntax UE friendly
using FText = std::string;
using int32 = int;

// function prototypes outside of a class
void PlayGame();
void PrintGameSummary();
void PrintIntro();
bool AskToPlayAgain();
FText GetValidGuess();

// instantiate a new game for reuse across replays
FBullCowGame BCGame;

int main(int argc, const char * argv[]) {
    do {
        PrintIntro();
        PlayGame();
        PrintGameSummary();
    } while (AskToPlayAgain());
    return 0; // exit the application
}

void PrintIntro() {
    std::cout << R"(
    ____  _    _ _      _       _____            _   _ _____     _____ ______          _______
    |  _ \| |  | | |    | |     / ____|     /\   | \ | |  __ \   / ____/ __ \ \        / / ____|
    | |_) | |  | | |    | |    | (___      /  \  |  \| | |  | | | |   | |  | \ \  /\  / / (___
    |  _ <| |  | | |    | |     \___ \    / /\ \ | . ` | |  | | | |   | |  | |\ \/  \/ / \___ \
    | |_) | |__| | |____| |____ ____) |  / ____ \| |\  | |__| | | |___| |__| | \  /\  /  ____) |
    |____/ \____/|______|______|_____/  /_/    \_\_| \_|_____/   \_____\____/   \/  \/  |_____/
    )" << '\n';
    std::cout << "\nWelcome To Bulls and Cows a fun word game written in C++." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n\n";
    
    return;
}

void PrintGameSummary() {
    if (BCGame.isGameWon()) {
        std::cout << "YOU WON!!!\n\n";
    } else {
        std::cout << "You lost sorry m8 :( better luck next time.\n\n";
    }
}

void PlayGame() {
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();

    while (!BCGame.isGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }
}

FText GetValidGuess() {
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " - \n";
        std::cout << "Enter your guess: ";
        getline (std::cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n\n";
                break;
            default:
                // assume the guess is valid
                break;
        }
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again with the same word (y/n)? ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
