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
        void wipeObject(CHARACTER);
        void checkScore();
        void checkTunnel();
        bool checkRotation(const COORDINATES&);
        void nextLevel();
        void resetLevel();
        void CharacterGoLeft(CHARACTER);
        void CharacterGoRight(CHARACTER);
        void CharacterGoDown(CHARACTER);
        void CharacterGoUp(CHARACTER);
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
