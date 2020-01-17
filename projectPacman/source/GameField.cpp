#include <iostream>
#include <windows.h>

#include "projectPacman/headers/GameField.hpp"

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
    for (auto y = 0; y < Y_SIZE(); ++y) {
        for (auto x = 0; x < X_SIZE(); ++x) {
            std::cout << mField_[y][x];
        }
        std::cout << std::endl;
    }
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
        updateChar(coord, c);
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
void GameField::resetField()
//------------------------------------------------------------------------------------------
{
    initGameField();
    printEnergizers();
    printGameObject();
}

//------------------------------------------------------------------------------------------
void GameField::printScore(const uint32_t score)
//------------------------------------------------------------------------------------------
{
    const uint8_t size = SCORE_PRINT_SIZE() / 2;
    char temp[size]={};
    snprintf(temp,size,"%*d",size-1,score);
    const uint8_t shift_X = SCORE_FIELD_X_START() + SCORE_PRINT_SIZE();
    const uint8_t shift_Y = SCORE_FIELD_Y_START() + SCORE_FIELD_Y_SIZE() / 2;
    for (auto i = 0; i < size; ++i) {
        COORDINATES coor(shift_X + i, shift_Y);
        setChar(coor, temp[i]);
    }
}

//------------------------------------------------------------------------------------------
void GameField::printLives(const uint32_t lives)
//------------------------------------------------------------------------------------------
{
    const uint8_t size = SCORE_PRINT_SIZE();
        wchar_t livesString[size] = {};
        swprintf_s(livesString, L"%d", lives);
        const uint8_t length = wcslen(livesString);
        const uint8_t shift_X = LIVES_FIELD_X_START() + SCORE_PRINT_SIZE();
        const uint8_t shift_Y = LIVES_FIELD_Y_START() + LIVES_FIELD_Y_SIZE() / 2;

        for (auto i = 0; i < length; ++i) {
            COORDINATES coor(shift_X + i, shift_Y);
            setChar(coor, livesString[i]);
        }
}

//------------------------------------------------------------------------------------------
void GameField::initField()
//------------------------------------------------------------------------------------------
{
    initFieldSize();
    printGameField();
    printScoreField();
    printLivesField();
}

//------------------------------------------------------------------------------------------
void GameField::initFieldSize()
//------------------------------------------------------------------------------------------
{
    mField_.resize(Y_SIZE());
    for (auto i = 0; i < Y_SIZE(); ++i) {
        mField_[i].resize(X_SIZE(), OBJECT_EMPTY());
    }
}

//------------------------------------------------------------------------------------------
void GameField::printGameField()
//------------------------------------------------------------------------------------------
{
    printRectangleBoudary(GAME_FIELD_X_START(), GAME_FIELD_Y_START(),
                          GAME_FIELD_X_FINISH(), GAME_FIELD_Y_FINISH());

    printTunnel();
    initGameField();
    printEnergizers();
    printGameObject();


}

//------------------------------------------------------------------------------------------
void GameField::initGameField()
//------------------------------------------------------------------------------------------
{
    printTesting();
    /*
    for (auto y = GAME_FIELD_Y_START(); y < GAME_FIELD_Y_SIZE() + BOUNDARY_SIZE() * 3; ++y) {
        for (auto x = GAME_FIELD_X_START(); x < GAME_FIELD_X_SIZE() -1 ; ++x) {
            setChar(x, y ,SMALLPOINT_SYMBOL);
        }
    }
    */
}

//------------------------------------------------------------------------------------------
void GameField::printScoreField()
//------------------------------------------------------------------------------------------
{
    printRectangleBoudary(SCORE_FIELD_X_START(), SCORE_FIELD_Y_START(),
                          SCORE_FIELD_X_FINISH(), SCORE_FIELD_Y_FINISH());

    printTitle(SCORE_FIELD_X_START() + 2, SCORE_FIELD_Y_START() + SCORE_FIELD_Y_SIZE() / 2,
               L">Score:");
}

//------------------------------------------------------------------------------------------
void GameField::printTitle(const uint8_t x, const uint8_t y, const wchar_t* line)
//------------------------------------------------------------------------------------------
{
    if (line == nullptr) {
        return;
    }

    const uint8_t length = wcslen(line);
    const uint8_t shift_X = x;
    const uint8_t shift_Y = y;

    for (auto i = 0; i < length; ++i) {
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
                setChar(x1, i, BOUNDARY_SYMBOL());
            }
        }
        else if (y1 == y2) {
            for (auto i = x1; i <= x2; ++i) {
                setChar(i, y1, BOUNDARY_SYMBOL());
            }
        }
}
//------------------------------------------------------------------------------------------
void GameField::updateChar(const COORDINATES coord, const uint8_t c)
//------------------------------------------------------------------------------------------
{
    TCHAR tempC = static_cast<TCHAR>(c);
    static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    static DWORD dw;
    COORD chCoord;
    chCoord.X = static_cast<SHORT>(coord.first);
    chCoord.Y = static_cast<SHORT>(coord.second);
    WriteConsoleOutputCharacter(hStdOut, &tempC, 1, chCoord, &dw);
}

//------------------------------------------------------------------------------------------
void GameField::printTesting()
//------------------------------------------------------------------------------------------
{
    uint8_t x = GAME_OBJECT_12_X() ;
    uint8_t y = GAME_OBJECT_12_Y() + 2;
    for (uint8_t i = 0; i < 10; ++i) {
        for (uint8_t b = 0; b < 7; ++b) {
            setChar(x + i, y + b, SMALLPOINT_SYMBOL());
        }
    }
}

//------------------------------------------------------------------------------------------
void GameField::printLivesField()
//------------------------------------------------------------------------------------------
{
    printRectangleBoudary(LIVES_FIELD_X_START(), LIVES_FIELD_Y_START(),
                          LIVES_FIELD_X_FINISH(), LIVES_FIELD_Y_FINISH());
    printTitle(LIVES_FIELD_X_START() + 2, LIVES_FIELD_Y_START() + SCORE_FIELD_Y_SIZE() / 2,
               L">Lives:");
}

//------------------------------------------------------------------------------------------
void GameField::printRectangXY(const uint8_t x, const uint8_t y, const uint8_t sizeX, const uint8_t sizeY)
//------------------------------------------------------------------------------------------
{
    for (uint8_t i = 0; i < sizeX; ++i) {
        for (uint8_t b = 0; b < sizeY; ++b) {
            setChar(x + i, y + b, BOUNDARY_SYMBOL());
        }
    }
}

//------------------------------------------------------------------------------------------
void GameField::printTunnel()
//------------------------------------------------------------------------------------------
{
    setChar(TUNNEL_1_X(), TUNNEL_1_Y(), OBJECT_EMPTY());
    setChar(TUNNEL_2_X(),TUNNEL_2_Y(), OBJECT_EMPTY());
}

//------------------------------------------------------------------------------------------
void GameField::printEnergizers()
//------------------------------------------------------------------------------------------
{
    setChar(ENERGIZER_1_X(), ENERGIZER_1_Y(), ENERGIZER_SYMBOL());
    setChar(ENERGIZER_2_X(), ENERGIZER_2_Y(), ENERGIZER_SYMBOL());
    setChar(ENERGIZER_3_X(), ENERGIZER_3_Y(), ENERGIZER_SYMBOL());
    setChar(ENERGIZER_4_X(), ENERGIZER_4_Y(), ENERGIZER_SYMBOL());
}

//------------------------------------------------------------------------------------------
void GameField::printGameObject()
//------------------------------------------------------------------------------------------
{
    printRectangXY(GAME_OBJECT_1_X(),GAME_OBJECT_1_Y(), GAME_OBJECT_1_SIZE_X(),GAME_OBJECT_1_SIZE_Y());
    printRectangXY(GAME_OBJECT_2_X(),GAME_OBJECT_2_Y(), GAME_OBJECT_2_SIZE_X(),GAME_OBJECT_2_SIZE_Y());
    printRectangXY(GAME_OBJECT_3_X(),GAME_OBJECT_3_Y(), GAME_OBJECT_3_SIZE_X(),GAME_OBJECT_3_SIZE_Y());
    printRectangXY(GAME_OBJECT_4_X(),GAME_OBJECT_4_Y(), GAME_OBJECT_4_SIZE_X(),GAME_OBJECT_4_SIZE_Y());
    printRectangXY(GAME_OBJECT_5_X(),GAME_OBJECT_5_Y(), GAME_OBJECT_5_SIZE_X(),GAME_OBJECT_5_SIZE_Y());

    printRectangXY(GAME_OBJECT_6_X(),GAME_OBJECT_6_Y(), GAME_OBJECT_6_SIZE_X(),GAME_OBJECT_6_SIZE_Y());
    printRectangXY(GAME_OBJECT_7_X(),GAME_OBJECT_7_Y(), GAME_OBJECT_7_SIZE_X(),GAME_OBJECT_7_SIZE_Y());
    printRectangXY(GAME_OBJECT_8_X(),GAME_OBJECT_8_Y(), GAME_OBJECT_8_SIZE_X(),GAME_OBJECT_8_SIZE_Y());
    printRectangXY(GAME_OBJECT_9_X(),GAME_OBJECT_9_Y(), GAME_OBJECT_9_SIZE_X(),GAME_OBJECT_9_SIZE_Y());
    printRectangXY(GAME_OBJECT_10_X(),GAME_OBJECT_10_Y(), GAME_OBJECT_10_SIZE_X(),GAME_OBJECT_10_SIZE_Y());

    printRectangXY(GAME_OBJECT_11_X(),GAME_OBJECT_11_Y(), GAME_OBJECT_11_SIZE_X(),GAME_OBJECT_11_SIZE_Y());
    printRectangXY(GAME_OBJECT_12_X(),GAME_OBJECT_12_Y(), GAME_OBJECT_12_SIZE_X(),GAME_OBJECT_12_SIZE_Y());
    printRectangXY(GAME_OBJECT_13_X(),GAME_OBJECT_13_Y(), GAME_OBJECT_13_SIZE_X(),GAME_OBJECT_13_SIZE_Y());
    printRectangXY(GAME_OBJECT_14_X(),GAME_OBJECT_14_Y(), GAME_OBJECT_14_SIZE_X(),GAME_OBJECT_14_SIZE_Y());
    printRectangXY(GAME_OBJECT_15_X(),GAME_OBJECT_15_Y(), GAME_OBJECT_15_SIZE_X(),GAME_OBJECT_15_SIZE_Y());

    // 16

    printRectangXY(GAME_OBJECT_17_X(),GAME_OBJECT_17_Y(), GAME_OBJECT_17_SIZE_X(),GAME_OBJECT_17_SIZE_Y());
    printRectangXY(GAME_OBJECT_18_X(),GAME_OBJECT_18_Y(), GAME_OBJECT_18_SIZE_X(),GAME_OBJECT_18_SIZE_Y());
    printRectangXY(GAME_OBJECT_19_X(),GAME_OBJECT_19_Y(), GAME_OBJECT_19_SIZE_X(),GAME_OBJECT_19_SIZE_Y());
    printRectangXY(GAME_OBJECT_20_X(),GAME_OBJECT_20_Y(), GAME_OBJECT_20_SIZE_X(),GAME_OBJECT_20_SIZE_Y());
    printRectangXY(GAME_OBJECT_21_X(),GAME_OBJECT_21_Y(), GAME_OBJECT_21_SIZE_X(),GAME_OBJECT_21_SIZE_Y());

    printRectangXY(GAME_OBJECT_22_X(),GAME_OBJECT_22_Y(), GAME_OBJECT_22_SIZE_X(),GAME_OBJECT_22_SIZE_Y());
    printRectangXY(GAME_OBJECT_23_X(),GAME_OBJECT_23_Y(), GAME_OBJECT_23_SIZE_X(),GAME_OBJECT_23_SIZE_Y());
    printRectangXY(GAME_OBJECT_24_X(),GAME_OBJECT_24_Y(), GAME_OBJECT_24_SIZE_X(),GAME_OBJECT_24_SIZE_Y());
    printRectangXY(GAME_OBJECT_25_X(),GAME_OBJECT_25_Y(), GAME_OBJECT_25_SIZE_X(),GAME_OBJECT_25_SIZE_Y());
    printRectangXY(GAME_OBJECT_26_X(),GAME_OBJECT_26_Y(), GAME_OBJECT_26_SIZE_X(),GAME_OBJECT_26_SIZE_Y());

    printRectangXY(GAME_OBJECT_27_X(),GAME_OBJECT_27_Y(), GAME_OBJECT_27_SIZE_X(),GAME_OBJECT_27_SIZE_Y());
    printRectangXY(GAME_OBJECT_28_X(),GAME_OBJECT_28_Y(), GAME_OBJECT_28_SIZE_X(),GAME_OBJECT_28_SIZE_Y());
    printRectangXY(GAME_OBJECT_29_X(),GAME_OBJECT_29_Y(), GAME_OBJECT_29_SIZE_X(),GAME_OBJECT_29_SIZE_Y());
    printRectangXY(GAME_OBJECT_30_X(),GAME_OBJECT_30_Y(), GAME_OBJECT_30_SIZE_X(),GAME_OBJECT_30_SIZE_Y());
    printRectangXY(GAME_OBJECT_31_X(),GAME_OBJECT_31_Y(), GAME_OBJECT_31_SIZE_X(),GAME_OBJECT_31_SIZE_Y());
    printRectangXY(GAME_OBJECT_32_X(),GAME_OBJECT_32_Y(), GAME_OBJECT_32_SIZE_X(),GAME_OBJECT_32_SIZE_Y());
    printRectangXY(GAME_OBJECT_33_X(),GAME_OBJECT_33_Y(), GAME_OBJECT_33_SIZE_X(),GAME_OBJECT_33_SIZE_Y());

    printRectangXY(GAME_OBJECT_34_X(),GAME_OBJECT_34_Y(), GAME_OBJECT_34_SIZE_X(),GAME_OBJECT_34_SIZE_Y());
    printRectangXY(GAME_OBJECT_35_X(),GAME_OBJECT_35_Y(), GAME_OBJECT_35_SIZE_X(),GAME_OBJECT_35_SIZE_Y());
    printRectangXY(GAME_OBJECT_36_X(),GAME_OBJECT_36_Y(), GAME_OBJECT_36_SIZE_X(),GAME_OBJECT_36_SIZE_Y());
}



