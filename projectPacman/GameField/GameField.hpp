#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

#include <vector>
#include <stdint.h>

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
        void printScore();
        void resetField();

    private:
        void initField();
        void initFieldSize();
        void printRectangleBoudary(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t y2);
        void printLine(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2);

        std::vector <std::vector<uint8_t>> mField_;
};

#endif // GAMEFIELD_HPP
