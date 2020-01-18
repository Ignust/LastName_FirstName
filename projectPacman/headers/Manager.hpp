#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <memory>

#include "projectPacman/headers/GameField.hpp"
#include "projectPacman/headers/Keybord.hpp"
#include "projectPacman/headers/Pacman.hpp"
#include "projectPacman/headers/tools/Types.hpp"
#include "projectPacman/headers/Ghost.hpp"
#include "projectPacman/headers/ICharacter.hpp"

class Manager {
    public:
        Manager();
        ~Manager();

        void checkUserAction();
        void update();
        void showField();
        bool gameOver();
        void resetGame();

    private:

        void processingPressedButton();
        void wipeObject(const CHARACTER);
        void checkScore();
        void checkTunnel();
        bool checkRotation(const COORDINATES&);
        void nextLevel();
        void resetLevel();
        void characterGoLeft(const CHARACTER);
        void characterGoRight(const CHARACTER);
        void characterGoDown(const CHARACTER);
        void characterGoUp(const CHARACTER);
        void updatePacman();
        void updateGhosts();
        void drawCharacter(const CHARACTER);
        void checkCollisionWithCharacters(const CHARACTER);
        void decrementLives();

        GameField mField_;
        Keybord mKeybord_;
        CHARACTER mPacman_;
        uint32_t mScore_;
        uint32_t mLives_;
        uint8_t mSmallPoints_;
        uint8_t mMazeLevel_;
        bool mGameOver_;
        GHOST mBlinky_;
};

#endif // MANAGER_HPP
