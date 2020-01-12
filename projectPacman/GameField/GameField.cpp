#include <iostream>
#include <windows.h>

#include "GameField.hpp"


//------------------------------------------------------------------------------------------
GameField::GameField()
    : mField_()
//------------------------------------------------------------------------------------------
{
    initField();
}

//------------------------------------------------------------------------------------------
GameField::~GameField()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void GameField::showField()
//------------------------------------------------------------------------------------------
{
    system("cls");
    for (auto y = 0; y < Y_SIZE; ++y) {
        for (auto x = 0; x < X_SIZE; ++x) {
            std::cout << mField_[y][x];
        }
        std::cout << std::endl;
    }
    //system("pause");
}

//------------------------------------------------------------------------------------------
void GameField::setChar(const uint8_t x, const uint8_t y, const uint8_t c)
//------------------------------------------------------------------------------------------
{
    mField_[y][x] = c;
}

//------------------------------------------------------------------------------------------
void GameField::setChar(const COORDINATES coord,const uint8_t c)
//------------------------------------------------------------------------------------------
{
    mField_[coord.second][coord.first] = c;
}

//------------------------------------------------------------------------------------------
uint8_t GameField::getChar(const uint8_t x, const uint8_t y)
//------------------------------------------------------------------------------------------
{
    return mField_[y][x];
}

//------------------------------------------------------------------------------------------
uint8_t GameField::getChar(const COORDINATES coord)
//------------------------------------------------------------------------------------------
{
    return mField_[coord.second][coord.first];
}

//------------------------------------------------------------------------------------------
void GameField::printScore()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void GameField::resetField()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void GameField::printScore(uint32_t score)
//------------------------------------------------------------------------------------------
{
    const uint8_t size = 10;
        wchar_t scoreString[size] = {};
        swprintf_s(scoreString, L"%d", score);
        const uint8_t length = wcslen(scoreString);
        const uint8_t shift_X = SCORE_FIELD_X_START + 10;
        const uint8_t shift_Y = SCORE_FIELD_Y_START + SCORE_FIELD_Y_SIZE / 2;

        for (uint8_t i = 0; i < length; ++i) {
            setChar(shift_X + i, shift_Y, scoreString[i]);
        }
}

//------------------------------------------------------------------------------------------
void GameField::initField()
//------------------------------------------------------------------------------------------
{
    initFieldSize();
    printGameField();
    printScoreField();

}

//------------------------------------------------------------------------------------------
void GameField::initFieldSize()
//------------------------------------------------------------------------------------------
{
    mField_.resize(Y_SIZE);
    for (auto i = 0; i < Y_SIZE; ++i) {
        mField_[i].resize(X_SIZE, OBJECT_EMPTY);
    }
}

//------------------------------------------------------------------------------------------
void GameField::printGameField()
//------------------------------------------------------------------------------------------
{
    printRectangleBoudary(GAME_FIELD_X_START, GAME_FIELD_Y_START,
                          GAME_FIELD_X_FINISH, GAME_FIELD_Y_FINISH);
}

//------------------------------------------------------------------------------------------
void GameField::printScoreField()
//------------------------------------------------------------------------------------------
{
    printRectangleBoudary(SCORE_FIELD_X_START, SCORE_FIELD_Y_START,
                          SCORE_FIELD_X_FINISH, SCORE_FIELD_Y_FINISH);
    printScoreTitle(L">Score:");
}

//------------------------------------------------------------------------------------------
void GameField::printScoreTitle(const wchar_t* line)
//------------------------------------------------------------------------------------------
{
    if (line == nullptr) {
        return;
    }

    const uint8_t length = wcslen(line);
    const uint8_t shift_X = SCORE_FIELD_X_START + 2;
    const uint8_t shift_Y = SCORE_FIELD_Y_START + SCORE_FIELD_Y_SIZE / 2;

    for (uint8_t i = 0; i < length; ++i) {
        setChar(shift_X + i, shift_Y, line[i]);
    }
}

//------------------------------------------------------------------------------------------
void GameField::printRectangleBoudary(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t y2)
//------------------------------------------------------------------------------------------
{
    printLine(x1 - 1, y1 - 1, x2 -1 , y1 - 1);
    printLine(x1 - 1, y2 - 1, x2 - 1 , y2 - 1);
    printLine(x1 - 1, y1 - 1, x1 - 1, y2 - 1);
    printLine(x2 - 1, y1 - 1, x2 - 1, y2 - 1);
}

//------------------------------------------------------------------------------------------
void GameField::printLine(const uint8_t x1, const uint8_t y1, const uint8_t x2, const uint8_t  y2)
//------------------------------------------------------------------------------------------
{
    if (x1 == x2) {
            for (auto i = y1; i <= y2; ++i) {
                setChar(x1, i, BOUNDARY_SYMBOL);
            }
        }
        else if (y1 == y2) {
            for (auto i = x1; i <= x2; ++i) {
                setChar(i, y1, BOUNDARY_SYMBOL);
            }
        }
}




