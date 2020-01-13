#ifndef TYPES_HPP
#define TYPES_HPP

#include <utility>
#include <stdint.h>

#define INIT_LIVES 3
#define X_SIZE              29
#define Y_SIZE              39

#define BOTTOM_LINE_SIZE    3

#define SMALLPOINT_SYMBOL        0x002E			// see UNICODE table
#define BOUNDARY_SYMBOL     0x0023			// see UNICODE table
#define OBJECT_SYMBOL       0x260A			// see UNICODE table
#define PACMAN_SYMBOL       64
#define OBJECT_EMPTY        0x0020			// see UNICODE table

#define BOUNDARY_SIZE           1

#define GAME_FIELD_X_SIZE       28
#define GAME_FIELD_Y_SIZE       31
#define SCORE_FIELD_X_SIZE      GAME_FIELD_X_SIZE
#define SCORE_FIELD_Y_SIZE      3
#define LIVES_FIELD_X_SIZE      SCORE_FIELD_X_SIZE
#define LIVES_FIELD_Y_SIZE      SCORE_FIELD_Y_SIZE

#define START_X_PACMAN      15
#define START_Y_PACMAN      (15 + GAME_FIELD_Y_START)

#define GAME_FIELD_X_START      BOUNDARY_SIZE
#define GAME_FIELD_X_FINISH     (GAME_FIELD_X_START + GAME_FIELD_X_SIZE - 1)
#define GAME_FIELD_Y_START      (BOUNDARY_SIZE *2 + SCORE_FIELD_Y_SIZE )
#define GAME_FIELD_Y_FINISH     (GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE - 1)

#define SCORE_FIELD_X_START		GAME_FIELD_X_START
#define SCORE_FIELD_X_FINISH	GAME_FIELD_X_FINISH
#define SCORE_FIELD_Y_START		BOUNDARY_SIZE
#define SCORE_FIELD_Y_FINISH	(SCORE_FIELD_Y_START + SCORE_FIELD_Y_SIZE+ BOUNDARY_SIZE)

#define LIVES_FIELD_X_START     GAME_FIELD_X_START
#define LIVES_FIELD_X_FINISH    GAME_FIELD_X_FINISH
#define LIVES_FIELD_Y_START     (GAME_FIELD_Y_START + GAME_FIELD_Y_SIZE - 1)
#define LIVES_FIELD_Y_FINISH    (GAME_FIELD_Y_FINISH + BOUNDARY_SIZE * 4)

//#define MAIN_WINDOWS_X_SIZE (3*BOUNDARY_SIZE+GAME_FIELD_X_SIZE+STATUS_FIELD_X_SIZE-1)
//#define MAIN_WINDOWS_Y_SIZE (3*BOUNDARY_SIZE+GAME_FIELD_Y_SIZE+SCORE_FIELD_Y_SIZE-1)

//#define FULL_LINE_X (GAME_FIELD_X_SIZE*OBJECT_SYMBOL)
//#define EMPTY_LINE_X (GAME_FIELD_X_SIZE*SPACE_SYMBOL)

//#define TIME_AUTO_SHIFT (1)
//#define TIME_BETWEEN_ROTATES (0.1)

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


#endif // TYPES_HPP
