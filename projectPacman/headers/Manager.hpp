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
        void wipeObject(const Character&);
        void checkScore();
        void checkTunnel();
        bool checkRotation(const Coordinates&);
        void nextLevel();
        void resetLevel();
        void characterGoLeft(const Character&);
        void characterGoRight(const Character&);
        void characterGoDown(const Character&);
        void characterGoUp(const Character&);
        void updatePacman();
        void updateGhosts();
        void drawCharacter(const Character&);
        void checkCollisionWithCharacters(const Character&);
        void decrementLives();
        void updateBlinky();
        void updatePinky();

        GameField mField_;
        Keybord mKeybord_;
        Character mPacman_;
        uint32_t mScore_;
        uint32_t mLives_;
        uint8_t mSmallPoints_;
        uint8_t mMazeLevel_;
        bool mGameOver_;
        Character mBlinky_;
        Character mPinky_;
};

#endif // MANAGER_HPP
