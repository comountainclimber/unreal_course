#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main(int argc, const char * argv[]) {
    PrintIntro();

    // loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
        GetGuessAndPrintBack();
        cout << endl;
    }

    cout << endl;
    return 0;
}

void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    cout << "Welcome To Bulls and Cows" << endl;
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    return;
}

string GetGuessAndPrintBack() {
    string Guess = "";
    cout << "What is your guess? ";
    getline (cin, Guess);
    cout << "Your guess was " << Guess << "!!!";
    cout << endl;
    return Guess;
}
