#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
void PrintGuess();
bool AskToPlayAgain();
string GetGuess();

int main(int argc, const char * argv[]) {
    PrintIntro();
    do {
        PlayGame();
    } while (AskToPlayAgain());
    return 0; // exit the application
}

void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome To Bulls and Cows" << endl;
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    return;
}

void PrintGuess(string guess) {
    cout << "Your guess was " << guess << "!!!";
    cout << endl;
}

// loop for the number of turns asking for guesses
void PlayGame() {
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
        string Guess = GetGuess();
        PrintGuess(Guess);
        cout << endl;
    }
}

string GetGuess() {
    string Guess = "";
    cout << "What is your guess? ";
    getline (cin, Guess);
    return Guess;
}

bool AskToPlayAgain() {
    cout << "Do you want to play again? ";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
