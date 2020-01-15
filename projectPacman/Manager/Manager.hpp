#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <memory>

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
        void drawPacman();
        void processingPressedButton();
        void wipeObject(const COORDINATES);
        void updatePacmanDirection();
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
        void drawCharacter(std::shared_ptr<ICharacter>);

        GameField mField_;
        Keybord mKeybord_;
        Pacman mPacman_;
        uint32_t mScore_;
        uint32_t mLives_;
        uint8_t mSmallPoints_;
        uint8_t mMazeLevel_;
        bool mGameOver_;
        //Ghost mBlinky_;
        std::shared_ptr<ICharacter> mBlinky_;
};

#endif // MANAGER_HPP
