#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "projectPacman/GameField/GameField.hpp"
#include "projectPacman/Keybord/Keybord.hpp"
#include "projectPacman/Pacman/Pacman.hpp"
#include "projectPacman/Tools/Types.hpp"

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
        void drawPacman();
        void processingPressedButton();
        void wipeObject(COORDINATES);
        void updatePacmanDirection();
        void checkScore();
        void checkTunnel();
        bool checkRotation(const COORDINATES rotation);
        void nextLevel();
        void resetLevel();

        GameField mField_;
        Keybord mKeybord_;
        Pacman mPacman_;
        uint32_t mScore_;
        uint32_t mLives_;
        uint8_t mSmallPoints_;
        uint8_t mMazeLevel_;
        bool mGameOver_;
};

#endif // MANAGER_HPP
