#ifndef HANGMAN_BOARD_H
#define HANGMAN_BOARD_H
#include <iostream>
#include <vector>

class Board {
private:
    std::string theWord;
    int wordSize;
    std::vector<char> wordVector;    //using a vector so that I can change it as they guess correctly
    std::vector<char> incorrectGuesses;
    bool keepPlaying;
    int numberOfTrys;

public:
    Board(std::string chosenWord, int vectorSize);
    void DisplayBoard();
    void CreateBoard();
    void Evaluate(char guess);
    bool Check();
    int GetNumberOfTrys() const;
};


#endif //HANGMAN_BOARD_H
