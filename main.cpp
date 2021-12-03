#include <iostream>
#include "Board.h"
#include <vector>

std::string PickAWord() {
    srand(time(0));
    std::vector<std::string> wordBank = {"cougars", "book", "school", "university", "science", "study", "create", "stretch", "serve", "intelligence"};
    return wordBank.at(rand() % 10);
}

void PlayHangMan() {
    char guess;
    std::string theWord = PickAWord();
    int wordSize = theWord.size();
    Board gameBoard(theWord, wordSize);

    std::cout << "Here is the board: " << std::endl;
    gameBoard.CreateBoard();
    do {
        std::cout << "Guess a letter: ";
        std::cin >> guess;
        tolower(guess);
        std::cout << std::endl;
        gameBoard.Evaluate(guess);
        gameBoard.DisplayBoard();
    } while (gameBoard.Check());
    std::cout << "Congrats! You guessed it in " << gameBoard.GetNumberOfTrys() << " trys!" << std::endl;
}

int main() {
    char playAgain = 'n';

    std::cout << "Welcome to Hangman!" << std::endl << std::endl;
    std::cout << "I will provide a word and you will try to guess what the word is." << std::endl << std::endl;

    do {
        PlayHangMan();   //this way my gameBoard object can clear each time the function is called, and it cleans main up a little.
        std::cout << "Would you like to play again? (Enter 'y' for yes, 'n' for no)" << std::endl;
        std::cin >> playAgain;
        while (playAgain != 'y' && playAgain != 'n') {
            std::cout << "Incorrect input. Try again. (Enter 'y' for yes, 'n' for no)" << std::endl;
            std::cin >> playAgain;
        }
    } while (playAgain == 'y');

    std::cout << std::endl << "Thank you for playing! I hope you enjoyed it. Bye!" << std::endl;
    return 0;
}
