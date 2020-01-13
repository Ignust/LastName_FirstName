#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

#include <vector>

#include "projectPacman/Tools/Types.hpp"

class GameField {
    public:
        GameField();
        ~GameField();

        void showField();
        void setChar(const uint8_t x, const uint8_t y, const uint8_t c);
        void setChar(const COORDINATES,  const uint8_t c);
        uint8_t getChar(const uint8_t x, const uint8_t y);
        uint8_t getChar(const COORDINATES);
        //void printScore();
        void resetField();
        void printScore(const uint32_t);

    private:
        void initField();
        void initFieldSize();
        void printGameField();
        void printScoreField();
        void printScoreTitle(const wchar_t* line);
        void printRectangleBoudary(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t y2);
        void printLine(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2);
        void updateChar(const COORDINATES, const uint8_t c);
        void printTesting();

        std::vector <std::vector<uint8_t>> mField_;
};

#endif // GAMEFIELD_HPP
