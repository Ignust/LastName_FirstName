#ifndef TYPES_HPP
#define TYPES_HPP

#include <utility>
#include <stdint.h>
#include <memory>

constexpr uint8_t INIT_LIVES()           {return 3;}
constexpr uint8_t INIT_MAZE_LEVEL()      {return 1;}
constexpr uint8_t X_SIZE()               {return 29;}
constexpr uint8_t Y_SIZE()               {return 39;}
constexpr uint8_t INIT_SCORE()           {return 0;}

constexpr uint8_t BOTTOM_LINE_SIZE()       {return 3;}
constexpr uint8_t SMALLPOINT_AMOUNT()      {return 68;}//23
constexpr uint8_t MAZE_LEVEL_AMOUNT()      {return 255;}
constexpr uint8_t SMALLPOINT_SCORE()       {return 10;}
constexpr uint8_t ENERGIZER_SCORE()        {return 50;}


constexpr char SMALLPOINT_SYMBOL()        {return 0x2E;}
constexpr char BOUNDARY_SYMBOL()        {return 0x23;}
constexpr char PACMAN_SYMBOL()        {return 64;}
constexpr char BLINKY_SYMBOL()        {return 66;}
constexpr char OBJECT_EMPTY()        {return 0x20;}
constexpr char ENERGIZER_SYMBOL()        {return 'o';}

constexpr uint8_t BOUNDARY_SIZE()           {return 1;}

constexpr uint8_t START_X_PACMAN()           {return 15;}
constexpr uint8_t START_Y_PACMAN()           {return 18;}
constexpr uint8_t START_X_GHOST()           {return 15;}
constexpr uint8_t START_Y_GHOST()           {return 19;}

constexpr uint8_t SCORE_PRINT_SIZE()           {return 10;}
constexpr uint8_t LIVES_PRINT_SIZE()           {return 10;}

constexpr uint8_t GAME_FIELD_X_SIZE()           {return 28;}
constexpr uint8_t GAME_FIELD_Y_SIZE()           {return 31;}
constexpr uint8_t SCORE_FIELD_X_SIZE()           {return GAME_FIELD_X_SIZE();}
constexpr uint8_t SCORE_FIELD_Y_SIZE()           {return 3;}
constexpr uint8_t LIVES_FIELD_X_SIZE()           {return SCORE_FIELD_X_SIZE();}
constexpr uint8_t LIVES_FIELD_Y_SIZE()           {return SCORE_FIELD_Y_SIZE();}


constexpr uint8_t GAME_FIELD_X_START() {return BOUNDARY_SIZE();}
constexpr uint8_t GAME_FIELD_X_FINISH() {return (GAME_FIELD_X_START() + GAME_FIELD_X_SIZE() - 1);}
constexpr uint8_t GAME_FIELD_Y_START() {return (BOUNDARY_SIZE() *2 + SCORE_FIELD_Y_SIZE());}
constexpr uint8_t GAME_FIELD_Y_FINISH() {return (GAME_FIELD_Y_START() + GAME_FIELD_Y_SIZE() - 1);}

constexpr uint8_t SCORE_FIELD_X_START() {return GAME_FIELD_X_START();}
constexpr uint8_t SCORE_FIELD_X_FINISH() {return GAME_FIELD_X_FINISH();}
constexpr uint8_t SCORE_FIELD_Y_START() {return BOUNDARY_SIZE();}
constexpr uint8_t SCORE_FIELD_Y_FINISH() {return (SCORE_FIELD_Y_START() + SCORE_FIELD_Y_SIZE() + BOUNDARY_SIZE());}

constexpr uint8_t LIVES_FIELD_X_START() {return GAME_FIELD_X_START();}
constexpr uint8_t LIVES_FIELD_X_FINISH() {return GAME_FIELD_X_FINISH();}
constexpr uint8_t LIVES_FIELD_Y_START() {return (GAME_FIELD_Y_START() + GAME_FIELD_Y_SIZE() - 1);}
constexpr uint8_t LIVES_FIELD_Y_FINISH() {return (GAME_FIELD_Y_FINISH() + BOUNDARY_SIZE() * 4);}

constexpr uint8_t GAME_OBJECT_1_X() {return (GAME_FIELD_X_START() + BOUNDARY_SIZE());}
constexpr uint8_t GAME_OBJECT_1_Y() {return (GAME_FIELD_Y_START() + BOUNDARY_SIZE());}
constexpr uint8_t GAME_OBJECT_1_SIZE_X() {return 4;}
constexpr uint8_t GAME_OBJECT_1_SIZE_Y() {return 3;}
constexpr uint8_t GAME_OBJECT_2_X() {return (GAME_OBJECT_1_X() + GAME_OBJECT_1_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_2_Y() {return (GAME_FIELD_Y_START() + 1);}
constexpr uint8_t GAME_OBJECT_2_SIZE_X() {return 5;}
constexpr uint8_t GAME_OBJECT_2_SIZE_Y() {return 3;}
constexpr uint8_t GAME_OBJECT_3_X() {return (GAME_OBJECT_2_X() + GAME_OBJECT_2_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_3_Y() {return (GAME_FIELD_Y_START());}
constexpr uint8_t GAME_OBJECT_3_SIZE_X() {return 2;}
constexpr uint8_t GAME_OBJECT_3_SIZE_Y() {return 4;}
constexpr uint8_t GAME_OBJECT_4_X() {return (GAME_OBJECT_3_X() + GAME_OBJECT_3_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_4_Y() {return (GAME_FIELD_Y_START() + 1);}
constexpr uint8_t GAME_OBJECT_4_SIZE_X() {return 5;}
constexpr uint8_t GAME_OBJECT_4_SIZE_Y() {return 3;}
constexpr uint8_t GAME_OBJECT_5_X() {return (GAME_OBJECT_4_X() + GAME_OBJECT_4_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_5_Y() {return (GAME_FIELD_Y_START() + 1);}
constexpr uint8_t GAME_OBJECT_5_SIZE_X() {return 4;}
constexpr uint8_t GAME_OBJECT_5_SIZE_Y() {return 3;}


constexpr uint8_t GAME_OBJECT_6_X() {return (GAME_OBJECT_1_X());}
constexpr uint8_t GAME_OBJECT_6_Y() {return (GAME_OBJECT_1_Y() + GAME_OBJECT_1_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_6_SIZE_X() {return 4;}
constexpr uint8_t GAME_OBJECT_6_SIZE_Y() {return 2;}
constexpr uint8_t GAME_OBJECT_7_X() {return (GAME_OBJECT_6_X() + GAME_OBJECT_6_SIZE_X() + 1);}
constexpr uint8_t GAME_OBJECT_7_Y() {return (GAME_OBJECT_6_Y());}
constexpr uint8_t GAME_OBJECT_7_SIZE_X() {return 2;}
constexpr uint8_t GAME_OBJECT_7_SIZE_Y() {return 8;}
constexpr uint8_t GAME_OBJECT_8_X() {return (GAME_OBJECT_7_X() + GAME_OBJECT_7_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_8_Y() {return (GAME_OBJECT_6_Y());}
constexpr uint8_t GAME_OBJECT_8_SIZE_X() {return 8;}
constexpr uint8_t GAME_OBJECT_8_SIZE_Y() {return 2;}
constexpr uint8_t GAME_OBJECT_9_X() {return (GAME_OBJECT_8_X() + GAME_OBJECT_8_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_9_Y() {return (GAME_OBJECT_6_Y());}
constexpr uint8_t GAME_OBJECT_9_SIZE_X() {return GAME_OBJECT_7_SIZE_X();}
constexpr uint8_t GAME_OBJECT_9_SIZE_Y() {return GAME_OBJECT_7_SIZE_Y();}
constexpr uint8_t GAME_OBJECT_10_X() {return (GAME_OBJECT_9_X() + GAME_OBJECT_9_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_10_Y() {return (GAME_OBJECT_6_Y());}
constexpr uint8_t GAME_OBJECT_10_SIZE_X() {return GAME_OBJECT_6_SIZE_X();}
constexpr uint8_t GAME_OBJECT_10_SIZE_Y() {return GAME_OBJECT_6_SIZE_Y();}


constexpr uint8_t GAME_OBJECT_11_X() {return (GAME_FIELD_X_START());}
constexpr uint8_t GAME_OBJECT_11_Y() {return (GAME_OBJECT_6_Y() +GAME_OBJECT_6_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_11_SIZE_X() {return 5;}
constexpr uint8_t GAME_OBJECT_11_SIZE_Y() {return 5;}
constexpr uint8_t GAME_OBJECT_12_X() {return (GAME_OBJECT_11_X()  +GAME_OBJECT_11_SIZE_X() + GAME_OBJECT_7_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_12_Y() {return (GAME_OBJECT_11_Y());}
constexpr uint8_t GAME_OBJECT_12_SIZE_X() {return 3;}
constexpr uint8_t GAME_OBJECT_12_SIZE_Y() {return 2;}
constexpr uint8_t GAME_OBJECT_13_X() {return (GAME_OBJECT_12_X() + GAME_OBJECT_12_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_13_Y() {return (GAME_OBJECT_11_Y() - 1);}
constexpr uint8_t GAME_OBJECT_13_SIZE_X() {return 2;}
constexpr uint8_t GAME_OBJECT_13_SIZE_Y() {return 3;}
constexpr uint8_t GAME_OBJECT_14_X() {return (GAME_OBJECT_13_X() + GAME_OBJECT_13_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_14_Y() {return (GAME_OBJECT_11_Y());}
constexpr uint8_t GAME_OBJECT_14_SIZE_X() {return GAME_OBJECT_12_SIZE_X();}
constexpr uint8_t GAME_OBJECT_14_SIZE_Y() {return GAME_OBJECT_12_SIZE_Y();}
constexpr uint8_t GAME_OBJECT_15_X() {return (GAME_OBJECT_14_X() + GAME_OBJECT_9_SIZE_X() + GAME_OBJECT_14_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_15_Y() {return (GAME_OBJECT_11_Y());}
constexpr uint8_t GAME_OBJECT_15_SIZE_X() {return GAME_OBJECT_11_SIZE_X();}
constexpr uint8_t GAME_OBJECT_15_SIZE_Y() {return GAME_OBJECT_11_SIZE_Y();}

constexpr uint8_t GAME_OBJECT_16_X() {return (0);}
constexpr uint8_t GAME_OBJECT_16_Y() {return (0);}
constexpr uint8_t GAME_OBJECT_16_SIZE_X() {return (0);}
constexpr uint8_t GAME_OBJECT_16_SIZE_Y() {return (0);}

constexpr uint8_t GAME_OBJECT_17_X() {return (GAME_OBJECT_11_X());}
constexpr uint8_t GAME_OBJECT_17_Y() {return (GAME_OBJECT_11_Y() + GAME_OBJECT_11_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_17_SIZE_X() {return (GAME_OBJECT_11_SIZE_X());}
constexpr uint8_t GAME_OBJECT_17_SIZE_Y() {return (GAME_OBJECT_11_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_18_X() {return (GAME_OBJECT_17_X() + GAME_OBJECT_17_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_18_Y() {return (GAME_OBJECT_17_Y());}
constexpr uint8_t GAME_OBJECT_18_SIZE_X() {return (2);}
constexpr uint8_t GAME_OBJECT_18_SIZE_Y() {return (5);}
constexpr uint8_t GAME_OBJECT_21_X() {return (GAME_OBJECT_18_X() + GAME_OBJECT_18_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_21_Y() {return (GAME_OBJECT_17_Y() + 3);}
constexpr uint8_t GAME_OBJECT_21_SIZE_X() {return (GAME_OBJECT_8_SIZE_X());}
constexpr uint8_t GAME_OBJECT_21_SIZE_Y() {return ((GAME_OBJECT_8_SIZE_Y()));}
constexpr uint8_t GAME_OBJECT_19_X() {return (GAME_OBJECT_18_X() + GAME_OBJECT_18_SIZE_X() + GAME_OBJECT_21_SIZE_X() +2);}
constexpr uint8_t GAME_OBJECT_19_Y() {return (GAME_OBJECT_17_Y());}
constexpr uint8_t GAME_OBJECT_19_SIZE_X() {return (GAME_OBJECT_18_SIZE_X());}
constexpr uint8_t GAME_OBJECT_19_SIZE_Y() {return (GAME_OBJECT_18_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_20_X() {return (GAME_OBJECT_19_X() + GAME_OBJECT_19_SIZE_X() + 1);}
constexpr uint8_t GAME_OBJECT_20_Y() {return (GAME_OBJECT_17_Y());}
constexpr uint8_t GAME_OBJECT_20_SIZE_X() {return (GAME_OBJECT_11_SIZE_X());}
constexpr uint8_t GAME_OBJECT_20_SIZE_Y() {return (GAME_OBJECT_11_SIZE_Y());}

constexpr uint8_t GAME_OBJECT_22_X() {return (GAME_OBJECT_1_X());}
constexpr uint8_t GAME_OBJECT_22_Y() {return (GAME_OBJECT_17_Y()  + GAME_OBJECT_17_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_22_SIZE_X() {return (GAME_OBJECT_6_SIZE_X());}
constexpr uint8_t GAME_OBJECT_22_SIZE_Y() {return (GAME_OBJECT_6_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_23_X() {return (GAME_OBJECT_22_X() + GAME_OBJECT_22_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_23_Y() {return (GAME_OBJECT_22_Y());}
constexpr uint8_t GAME_OBJECT_23_SIZE_X() {return (5);}
constexpr uint8_t GAME_OBJECT_23_SIZE_Y() {return (2);}
constexpr uint8_t GAME_OBJECT_24_X() {return (GAME_OBJECT_23_X() + GAME_OBJECT_23_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_24_Y() {return (GAME_OBJECT_22_Y() -1);}
constexpr uint8_t GAME_OBJECT_24_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_24_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_25_X() {return (GAME_OBJECT_24_X() + GAME_OBJECT_24_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_25_Y() {return (GAME_OBJECT_22_Y());}
constexpr uint8_t GAME_OBJECT_25_SIZE_X() {return (GAME_OBJECT_23_SIZE_X());}
constexpr uint8_t GAME_OBJECT_25_SIZE_Y() {return (GAME_OBJECT_23_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_26_X() {return (GAME_OBJECT_25_X() + GAME_OBJECT_25_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_26_Y() {return (GAME_OBJECT_22_Y());}
constexpr uint8_t GAME_OBJECT_26_SIZE_X() {return (GAME_OBJECT_22_SIZE_X());}
constexpr uint8_t GAME_OBJECT_26_SIZE_Y() {return (GAME_OBJECT_22_SIZE_Y());}

constexpr uint8_t GAME_OBJECT_27_X() {return (GAME_OBJECT_11_X());}
constexpr uint8_t GAME_OBJECT_27_Y() {return (GAME_OBJECT_22_Y() + GAME_OBJECT_22_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_27_SIZE_X() {return (2);}
constexpr uint8_t GAME_OBJECT_27_SIZE_Y() {return (2);}
constexpr uint8_t GAME_OBJECT_28_X() {return (GAME_OBJECT_27_X() + GAME_OBJECT_27_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_28_Y() {return (GAME_OBJECT_27_Y() - 1);}
constexpr uint8_t GAME_OBJECT_28_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_28_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_29_X() {return (GAME_OBJECT_28_X() + GAME_OBJECT_28_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_29_Y() {return (GAME_OBJECT_27_Y());}
constexpr uint8_t GAME_OBJECT_29_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_29_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_30_X() {return (GAME_OBJECT_29_X() + GAME_OBJECT_29_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_30_Y() {return (GAME_OBJECT_27_Y());}
constexpr uint8_t GAME_OBJECT_30_SIZE_X() {return (GAME_OBJECT_8_SIZE_X());}
constexpr uint8_t GAME_OBJECT_30_SIZE_Y() {return (GAME_OBJECT_8_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_31_X() {return (GAME_OBJECT_30_X() + GAME_OBJECT_30_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_31_Y() {return (GAME_OBJECT_27_Y());}
constexpr uint8_t GAME_OBJECT_31_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_31_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_32_X() {return (GAME_OBJECT_31_X() + GAME_OBJECT_31_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_32_Y() {return (GAME_OBJECT_27_Y() -1);}
constexpr uint8_t GAME_OBJECT_32_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_32_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_33_X() {return (GAME_OBJECT_32_X() + GAME_OBJECT_32_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_33_Y() {return (GAME_OBJECT_27_Y());}
constexpr uint8_t GAME_OBJECT_33_SIZE_X() {return (GAME_OBJECT_27_SIZE_X());}
constexpr uint8_t GAME_OBJECT_33_SIZE_Y() {return (GAME_OBJECT_27_SIZE_Y());}

constexpr uint8_t GAME_OBJECT_34_X() {return (GAME_OBJECT_1_X());}
constexpr uint8_t GAME_OBJECT_34_Y() {return (GAME_OBJECT_27_Y() + GAME_OBJECT_27_SIZE_Y() + 1);}
constexpr uint8_t GAME_OBJECT_34_SIZE_X() {return (10);}
constexpr uint8_t GAME_OBJECT_34_SIZE_Y() {return (2);}
constexpr uint8_t GAME_OBJECT_35_X() {return (GAME_OBJECT_34_X() + GAME_OBJECT_34_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_35_Y() {return (GAME_OBJECT_34_Y() -1);}
constexpr uint8_t GAME_OBJECT_35_SIZE_X() {return (GAME_OBJECT_13_SIZE_X());}
constexpr uint8_t GAME_OBJECT_35_SIZE_Y() {return (GAME_OBJECT_13_SIZE_Y());}
constexpr uint8_t GAME_OBJECT_36_X() {return (GAME_OBJECT_35_X() + GAME_OBJECT_35_SIZE_X() +1);}
constexpr uint8_t GAME_OBJECT_36_Y() {return (GAME_OBJECT_34_Y());}
constexpr uint8_t GAME_OBJECT_36_SIZE_X() {return (GAME_OBJECT_34_SIZE_X());}
constexpr uint8_t GAME_OBJECT_36_SIZE_Y() {return (GAME_OBJECT_34_SIZE_Y());}

constexpr uint8_t TUNNEL_1_X() {return (GAME_FIELD_X_START() -1);}
constexpr uint8_t TUNNEL_1_Y() {return (GAME_FIELD_Y_START() + GAME_FIELD_Y_SIZE() / 2 - BOUNDARY_SIZE() * 2);}
constexpr uint8_t TUNNEL_2_X() {return (GAME_FIELD_X_START() + GAME_FIELD_X_SIZE() - BOUNDARY_SIZE() * 2);}
constexpr uint8_t TUNNEL_2_Y() {return (GAME_FIELD_Y_START() + GAME_FIELD_Y_SIZE() / 2 - BOUNDARY_SIZE() * 2);}

constexpr uint8_t ENERGIZER_1_X() {return (GAME_FIELD_X_START());}
constexpr uint8_t ENERGIZER_1_Y() {return (GAME_FIELD_Y_START() + BOUNDARY_SIZE() * 2);}
constexpr uint8_t ENERGIZER_2_X() {return (GAME_FIELD_X_START()+GAME_FIELD_X_SIZE() - BOUNDARY_SIZE() * 3);}
constexpr uint8_t ENERGIZER_2_Y() {return (GAME_FIELD_Y_START() + BOUNDARY_SIZE() *2);}
constexpr uint8_t ENERGIZER_3_X() {return (GAME_FIELD_X_START());}
constexpr uint8_t ENERGIZER_3_Y() {return (GAME_FIELD_Y_START() +GAME_FIELD_Y_SIZE() - 9);}
constexpr uint8_t ENERGIZER_4_X() {return (GAME_FIELD_X_START()+GAME_FIELD_X_SIZE() - BOUNDARY_SIZE() *3);}
constexpr uint8_t ENERGIZER_4_Y() {return (GAME_FIELD_Y_START() +GAME_FIELD_Y_SIZE() - 9);}


class ICharacter;
typedef std::pair<uint8_t,uint8_t> COORDINATES;
typedef std::shared_ptr<ICharacter> CHARACTER;

enum E_BUTTONS {
    A_Button =      97,
    S_Button =      115,
    D_Button =      100,
    W_Button =      119,
    Left_Button =   75,
    Right_Button =  77,
    Down_Button =   80,
    UP_Button =     72,
    Spase_Button =  32,
    Auto_Button =   0
};

enum E_TUNNEL {
    TUNNEL_1 =  1,
    TUNNEL_2 =  2
};


#endif // TYPES_HPP
