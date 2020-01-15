#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "projectPacman/GameField/GameField.hpp"
#include "projectPacman/Keybord/Keybord.hpp"
#include "projectPacman/Pacman/Pacman.hpp"
#include "projectPacman/Tools/Types.hpp"
#include "projectPacman/Ghost/Ghost.hpp"
#include "projectPacman/ICharacter/ICharacter.hpp"

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
        void wipeObject(CHARACTER);
        void checkScore();
        void checkTunnel();
        bool checkRotation(const COORDINATES&);
        void nextLevel();
        void resetLevel();
        void PacmanGoLeft();
        void PacmanGoRight();
        void PacmanGoDown();
        void PacmanGoUp();
        void updatePacman();
        void updateGhosts();
        void drawCharacter(CHARACTER);
        void updateCharacterDirection(CHARACTER);
        void checkCollisionWithCharacters(CHARACTER);
        void decrementLives();

        GameField mField_;
        Keybord mKeybord_;
        CHARACTER mPacman_;
        uint32_t mScore_;
        uint32_t mLives_;
        uint8_t mSmallPoints_;
        uint8_t mMazeLevel_;
        bool mGameOver_;
        CHARACTER mBlinky_;
};

#endif // MANAGER_HPP
