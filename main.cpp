#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("words.txt");
    if (!file){cout << "Can not find the words!\n"; return 1;}
    else{
        int lines = 0;
        string line;
        string word;
        int currentLine = 0;
        int lineCount;
        while (getline(file, line)) {lineCount=lines++;}
        file.close();
        srand(static_cast<unsigned int>(time(0)));
        int randomLine = rand() % lineCount;
        file.open("words.txt");
        while (getline(file, line)) {
            if(currentLine == randomLine) {
            word = line;
            break;}
            currentLine++;
        }
        file.close();
    cout << "Welcome to Hangman!" << endl;
    //string word = "house"; // Replace with code to choose a random word
    int wordLength = word.length();
    string guessedWord(wordLength, 'X');
    int attempts = 7;
    char guessedLetter;
    bool correctGuess;

    while (attempts > 0 && guessedWord != word) {
        cout << "Current word: " << guessedWord << endl;
        cout << "Guess a single letter: ";
        cin >> guessedLetter;
        correctGuess = false;

        for (int i = 0; i < wordLength; ++i) {
            if (word[i] == guessedLetter) {
                guessedWord[i] = guessedLetter;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            attempts--;
            cout << "Incorrect! You have " << attempts << " attempts left." << endl;
        } else {
            cout << "Correct!" << endl;
        }
    }

    if (guessedWord == word) {
        cout << "Congratulations! You've guessed the word: " << word << endl;
    } else {
        cout << "You've run out of attempts. The word was: " << word << endl;
    }
    }
    return 0;
}
