#ifndef TYPES_HPP
#define TYPES_HPP

#include <utility>
#include <stdint.h>

#define INIT_LIVES          3
#define INIT_MAZE_LEVEL     1
#define X_SIZE              29
#define Y_SIZE              39

#define BOTTOM_LINE_SIZE    3
#define SMALLPOINT_AMOUNT   69//23
#define MAZE_LEVEL_AMOUNT   255

#define SMALLPOINT_SYMBOL   0x002E
#define BOUNDARY_SYMBOL     0x0023
#define OBJECT_SYMBOL       0x260A
#define PACMAN_SYMBOL       64
#define OBJECT_EMPTY        0x0020
#define ENERGIZER_SYMBOL    'o'

#define BOUNDARY_SIZE           1

#define TUNNEL_1_X      GAME_FIELD_X_START -1
#define TUNNEL_1_Y      GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE/2 - BOUNDARY_SIZE * 2
#define TUNNEL_2_X      GAME_FIELD_X_START + GAME_FIELD_X_SIZE - BOUNDARY_SIZE * 2
#define TUNNEL_2_Y      GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE/2 - BOUNDARY_SIZE * 2

#define GAME_FIELD_X_SIZE       28
#define GAME_FIELD_Y_SIZE       31
#define SCORE_FIELD_X_SIZE      GAME_FIELD_X_SIZE
#define SCORE_FIELD_Y_SIZE      3
#define LIVES_FIELD_X_SIZE      SCORE_FIELD_X_SIZE
#define LIVES_FIELD_Y_SIZE      SCORE_FIELD_Y_SIZE

#define GAME_FIELD_X_START      BOUNDARY_SIZE
#define GAME_FIELD_X_FINISH     (GAME_FIELD_X_START + GAME_FIELD_X_SIZE - 1)
#define GAME_FIELD_Y_START      (BOUNDARY_SIZE *2 + SCORE_FIELD_Y_SIZE )
#define GAME_FIELD_Y_FINISH     (GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE - 1)

#define SCORE_FIELD_X_START     GAME_FIELD_X_START
#define SCORE_FIELD_X_FINISH    GAME_FIELD_X_FINISH
#define SCORE_FIELD_Y_START     BOUNDARY_SIZE
#define SCORE_FIELD_Y_FINISH    (SCORE_FIELD_Y_START + SCORE_FIELD_Y_SIZE+ BOUNDARY_SIZE)

#define LIVES_FIELD_X_START     GAME_FIELD_X_START
#define LIVES_FIELD_X_FINISH    GAME_FIELD_X_FINISH
#define LIVES_FIELD_Y_START     (GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE - 1)
#define LIVES_FIELD_Y_FINISH    (GAME_FIELD_Y_FINISH + BOUNDARY_SIZE * 4)


#define GAME_OBJECT_1_X         GAME_FIELD_X_START + 1
#define GAME_OBJECT_1_Y         GAME_FIELD_Y_START + 1
#define GAME_OBJECT_1_SIZE_X    4
#define GAME_OBJECT_1_SIZE_Y    3
#define GAME_OBJECT_2_X         GAME_OBJECT_1_X + GAME_OBJECT_1_SIZE_X +1
#define GAME_OBJECT_2_Y         GAME_FIELD_Y_START + 1
#define GAME_OBJECT_2_SIZE_X    5
#define GAME_OBJECT_2_SIZE_Y    3
#define GAME_OBJECT_3_X         GAME_OBJECT_2_X + GAME_OBJECT_2_SIZE_X +1
#define GAME_OBJECT_3_Y         GAME_FIELD_Y_START
#define GAME_OBJECT_3_SIZE_X    2
#define GAME_OBJECT_3_SIZE_Y    4
#define GAME_OBJECT_4_X         GAME_OBJECT_3_X + GAME_OBJECT_3_SIZE_X +1
#define GAME_OBJECT_4_Y         GAME_FIELD_Y_START + 1
#define GAME_OBJECT_4_SIZE_X    5
#define GAME_OBJECT_4_SIZE_Y    3
#define GAME_OBJECT_5_X         GAME_OBJECT_4_X + GAME_OBJECT_4_SIZE_X +1
#define GAME_OBJECT_5_Y         GAME_FIELD_Y_START + 1
#define GAME_OBJECT_5_SIZE_X    4
#define GAME_OBJECT_5_SIZE_Y    3

#define GAME_OBJECT_6_X         GAME_OBJECT_1_X
#define GAME_OBJECT_6_Y         GAME_OBJECT_1_Y + GAME_OBJECT_1_SIZE_Y + 1
#define GAME_OBJECT_6_SIZE_X    4
#define GAME_OBJECT_6_SIZE_Y    2
#define GAME_OBJECT_7_X         GAME_OBJECT_6_X + GAME_OBJECT_6_SIZE_X + 1
#define GAME_OBJECT_7_Y         GAME_OBJECT_6_Y
#define GAME_OBJECT_7_SIZE_X    2
#define GAME_OBJECT_7_SIZE_Y    8
#define GAME_OBJECT_8_X         GAME_OBJECT_7_X + GAME_OBJECT_7_SIZE_X +1
#define GAME_OBJECT_8_Y         GAME_OBJECT_6_Y
#define GAME_OBJECT_8_SIZE_X    8
#define GAME_OBJECT_8_SIZE_Y    2
#define GAME_OBJECT_9_X         GAME_OBJECT_8_X + GAME_OBJECT_8_SIZE_X +1
#define GAME_OBJECT_9_Y         GAME_OBJECT_6_Y
#define GAME_OBJECT_9_SIZE_X    GAME_OBJECT_7_SIZE_X
#define GAME_OBJECT_9_SIZE_Y    GAME_OBJECT_7_SIZE_Y
#define GAME_OBJECT_10_X         GAME_OBJECT_9_X + GAME_OBJECT_9_SIZE_X +1
#define GAME_OBJECT_10_Y         GAME_OBJECT_6_Y
#define GAME_OBJECT_10_SIZE_X    GAME_OBJECT_6_SIZE_X
#define GAME_OBJECT_10_SIZE_Y    GAME_OBJECT_6_SIZE_Y

#define GAME_OBJECT_11_X         GAME_FIELD_X_START
#define GAME_OBJECT_11_Y         GAME_OBJECT_6_Y +GAME_OBJECT_6_SIZE_Y + 1
#define GAME_OBJECT_11_SIZE_X    5
#define GAME_OBJECT_11_SIZE_Y    5
#define GAME_OBJECT_12_X         GAME_OBJECT_11_X  +GAME_OBJECT_11_SIZE_X+ GAME_OBJECT_7_SIZE_X +1
#define GAME_OBJECT_12_Y         GAME_OBJECT_11_Y
#define GAME_OBJECT_12_SIZE_X    3
#define GAME_OBJECT_12_SIZE_Y    2
#define GAME_OBJECT_13_X         GAME_OBJECT_12_X + GAME_OBJECT_12_SIZE_X +1
#define GAME_OBJECT_13_Y         GAME_OBJECT_11_Y -1
#define GAME_OBJECT_13_SIZE_X    2
#define GAME_OBJECT_13_SIZE_Y    3
#define GAME_OBJECT_14_X         GAME_OBJECT_13_X + GAME_OBJECT_13_SIZE_X +1
#define GAME_OBJECT_14_Y         GAME_OBJECT_11_Y
#define GAME_OBJECT_14_SIZE_X    GAME_OBJECT_12_SIZE_X
#define GAME_OBJECT_14_SIZE_Y    GAME_OBJECT_12_SIZE_Y
#define GAME_OBJECT_15_X         GAME_OBJECT_14_X + GAME_OBJECT_9_SIZE_X + GAME_OBJECT_14_SIZE_X +1
#define GAME_OBJECT_15_Y         GAME_OBJECT_11_Y
#define GAME_OBJECT_15_SIZE_X    GAME_OBJECT_11_SIZE_X
#define GAME_OBJECT_15_SIZE_Y    GAME_OBJECT_11_SIZE_Y

#define GAME_OBJECT_16_X         0
#define GAME_OBJECT_16_Y         0
#define GAME_OBJECT_16_SIZE_X    0
#define GAME_OBJECT_16_SIZE_Y    0

#define GAME_OBJECT_17_X         GAME_OBJECT_11_X
#define GAME_OBJECT_17_Y         GAME_OBJECT_11_Y + GAME_OBJECT_11_SIZE_Y + 1
#define GAME_OBJECT_17_SIZE_X    GAME_OBJECT_11_SIZE_X
#define GAME_OBJECT_17_SIZE_Y    GAME_OBJECT_11_SIZE_Y
#define GAME_OBJECT_18_X         GAME_OBJECT_17_X + GAME_OBJECT_17_SIZE_X +1
#define GAME_OBJECT_18_Y         GAME_OBJECT_17_Y
#define GAME_OBJECT_18_SIZE_X    2
#define GAME_OBJECT_18_SIZE_Y    5
#define GAME_OBJECT_19_X         GAME_OBJECT_18_X + GAME_OBJECT_18_SIZE_X + GAME_OBJECT_21_SIZE_X +2
#define GAME_OBJECT_19_Y         GAME_OBJECT_17_Y
#define GAME_OBJECT_19_SIZE_X    GAME_OBJECT_18_SIZE_X
#define GAME_OBJECT_19_SIZE_Y    GAME_OBJECT_18_SIZE_Y
#define GAME_OBJECT_20_X         GAME_OBJECT_19_X + GAME_OBJECT_19_SIZE_X + 1
#define GAME_OBJECT_20_Y         GAME_OBJECT_17_Y
#define GAME_OBJECT_20_SIZE_X    GAME_OBJECT_11_SIZE_X
#define GAME_OBJECT_20_SIZE_Y    GAME_OBJECT_11_SIZE_Y
#define GAME_OBJECT_21_X         GAME_OBJECT_18_X + GAME_OBJECT_18_SIZE_X +1
#define GAME_OBJECT_21_Y         GAME_OBJECT_17_Y + 3
#define GAME_OBJECT_21_SIZE_X    GAME_OBJECT_8_SIZE_X
#define GAME_OBJECT_21_SIZE_Y    GAME_OBJECT_8_SIZE_Y

#define GAME_OBJECT_22_X         GAME_OBJECT_1_X
#define GAME_OBJECT_22_Y         GAME_OBJECT_17_Y  + GAME_OBJECT_17_SIZE_Y + 1
#define GAME_OBJECT_22_SIZE_X    GAME_OBJECT_6_SIZE_X
#define GAME_OBJECT_22_SIZE_Y    GAME_OBJECT_6_SIZE_Y
#define GAME_OBJECT_23_X         GAME_OBJECT_22_X + GAME_OBJECT_22_SIZE_X +1
#define GAME_OBJECT_23_Y         GAME_OBJECT_22_Y
#define GAME_OBJECT_23_SIZE_X    5
#define GAME_OBJECT_23_SIZE_Y    2
#define GAME_OBJECT_24_X         GAME_OBJECT_23_X + GAME_OBJECT_23_SIZE_X +1
#define GAME_OBJECT_24_Y         GAME_OBJECT_22_Y -1
#define GAME_OBJECT_24_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_24_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_25_X         GAME_OBJECT_24_X + GAME_OBJECT_24_SIZE_X +1
#define GAME_OBJECT_25_Y         GAME_OBJECT_22_Y
#define GAME_OBJECT_25_SIZE_X    GAME_OBJECT_23_SIZE_X
#define GAME_OBJECT_25_SIZE_Y    GAME_OBJECT_23_SIZE_Y
#define GAME_OBJECT_26_X         GAME_OBJECT_25_X + GAME_OBJECT_25_SIZE_X +1
#define GAME_OBJECT_26_Y         GAME_OBJECT_22_Y
#define GAME_OBJECT_26_SIZE_X    GAME_OBJECT_22_SIZE_X
#define GAME_OBJECT_26_SIZE_Y    GAME_OBJECT_22_SIZE_Y

#define GAME_OBJECT_27_X         GAME_OBJECT_11_X
#define GAME_OBJECT_27_Y         GAME_OBJECT_22_Y + GAME_OBJECT_22_SIZE_Y + 1
#define GAME_OBJECT_27_SIZE_X    2
#define GAME_OBJECT_27_SIZE_Y    2
#define GAME_OBJECT_28_X         GAME_OBJECT_27_X + GAME_OBJECT_27_SIZE_X +1
#define GAME_OBJECT_28_Y         GAME_OBJECT_27_Y - 1
#define GAME_OBJECT_28_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_28_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_29_X         GAME_OBJECT_28_X + GAME_OBJECT_28_SIZE_X +1
#define GAME_OBJECT_29_Y         GAME_OBJECT_27_Y
#define GAME_OBJECT_29_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_29_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_30_X         GAME_OBJECT_29_X + GAME_OBJECT_29_SIZE_X +1
#define GAME_OBJECT_30_Y         GAME_OBJECT_27_Y
#define GAME_OBJECT_30_SIZE_X    GAME_OBJECT_8_SIZE_X
#define GAME_OBJECT_30_SIZE_Y    GAME_OBJECT_8_SIZE_Y
#define GAME_OBJECT_31_X         GAME_OBJECT_30_X + GAME_OBJECT_30_SIZE_X +1
#define GAME_OBJECT_31_Y         GAME_OBJECT_27_Y
#define GAME_OBJECT_31_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_31_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_32_X         GAME_OBJECT_31_X + GAME_OBJECT_31_SIZE_X +1
#define GAME_OBJECT_32_Y         GAME_OBJECT_27_Y -1
#define GAME_OBJECT_32_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_32_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_33_X         GAME_OBJECT_32_X + GAME_OBJECT_32_SIZE_X +1
#define GAME_OBJECT_33_Y         GAME_OBJECT_27_Y
#define GAME_OBJECT_33_SIZE_X    GAME_OBJECT_27_SIZE_X
#define GAME_OBJECT_33_SIZE_Y    GAME_OBJECT_27_SIZE_Y

#define GAME_OBJECT_34_X         GAME_OBJECT_1_X
#define GAME_OBJECT_34_Y         GAME_OBJECT_27_Y + GAME_OBJECT_27_SIZE_Y + 1
#define GAME_OBJECT_34_SIZE_X    10
#define GAME_OBJECT_34_SIZE_Y    2
#define GAME_OBJECT_35_X         GAME_OBJECT_34_X + GAME_OBJECT_34_SIZE_X +1
#define GAME_OBJECT_35_Y         GAME_OBJECT_34_Y -1
#define GAME_OBJECT_35_SIZE_X    GAME_OBJECT_13_SIZE_X
#define GAME_OBJECT_35_SIZE_Y    GAME_OBJECT_13_SIZE_Y
#define GAME_OBJECT_36_X         GAME_OBJECT_35_X + GAME_OBJECT_35_SIZE_X +1
#define GAME_OBJECT_36_Y         GAME_OBJECT_34_Y
#define GAME_OBJECT_36_SIZE_X    GAME_OBJECT_34_SIZE_X
#define GAME_OBJECT_36_SIZE_Y    GAME_OBJECT_34_SIZE_Y

#define START_X_PACMAN 15
#define START_Y_PACMAN 18

//#define START_X_PACMAN      15
//#define START_Y_PACMAN      GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE/2

typedef std::pair<uint8_t,uint8_t> COORDINATES;

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
