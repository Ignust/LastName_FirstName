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

    private:
        void drawPacman();
        void processingPressedButton();
        void wipeObject(COORDINATES);
        void updatePacmanDirection();

        GameField mField_;
        Keybord mKeybord_;
        Pacman mPacman_;
        uint32_t mScore_;
};

#endif // MANAGER_HPP
