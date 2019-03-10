#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
void PrintGuess();
bool AskToPlayAgain();
std::string GetGuess();
FBullCowGame BCGame;

int main(int argc, const char * argv[]) {
    do {
        PrintIntro();
        PlayGame();
        // TODO: summarize the status of game
    } while (AskToPlayAgain());
    return 0; // exit the application
}

void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome To Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

void PrintGuess(std::string guess) {
    std::cout << "Your guess was " << guess << "!!!";
    std::cout << std::endl;
}

// loop for the number of turns asking for guesses
void PlayGame() {
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    // TODO: refactor to use while loop
    for (int i = 1; i <= MaxTries; i++) {
        std::string Guess = GetGuess(); // TODO: make loop checking valid guesses
        
        // Submit valid guess to the game print number of bulls and cows
        PrintGuess(Guess);
        std::cout << std::endl;
    }
}

std::string GetGuess() {
    std::string Guess = "";
    std::cout << "What is your guess? ";
    getline (std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again (y/n)? ";
    std::string Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
