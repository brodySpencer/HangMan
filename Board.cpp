#include "Board.h"

Board::Board(std::string chosenWord, int vectorSize) {
    theWord = chosenWord;
    wordSize = vectorSize;
    numberOfTrys = 0;
    keepPlaying = true;
}

void Board::CreateBoard() {
    char blank = '_';
    for (int i=0; i < wordSize; ++i) {
        wordVector.push_back(blank);
    }
    for (int i=0; i < wordVector.size(); ++i) {
        std::cout << wordVector.at(i) << " ";
    }
    std::cout << std::endl;
}

void Board::DisplayBoard() {
    for (int i=0; i < wordVector.size(); ++i) {
        std::cout << wordVector.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Incorrect Guesses: ";
    for (unsigned int i=0; i < incorrectGuesses.size(); ++i) {
        std::cout << incorrectGuesses.at(i) << " ";
    }
    std::cout << std::endl;
}

void Board::Evaluate(char guess) {
    if (theWord.find(guess) == std::string::npos) {
        std::cout << "Good Try" << std::endl;
        incorrectGuesses.push_back(guess);
    }
    else {
        std::cout << "Nice guess!" << std::endl;
        int index = 0;
        while (theWord.find(guess, index) != std::string::npos) {
            wordVector.at(theWord.find(guess, index)) = guess;     //replace '_' with correct guess
            index = theWord.find(guess, index) + 1;
        }
    }
    ++numberOfTrys;
}

bool Board::Check() {
    std::string tempString = "";       //I want to fill tempString with what the wordArray has to check if they found it.
    for (int i=1; i < wordSize; ++i) {
        tempString += wordVector.at(i);
    }
    if (tempString.find('_') == std::string::npos) {
        keepPlaying = false;
    }
    return keepPlaying;
}

int Board::GetNumberOfTrys() const {
    return numberOfTrys;
}