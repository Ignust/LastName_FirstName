#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "projectPacman/GameField/GameField.hpp"
#include "projectPacman/Keybord/Keybord.hpp"
#include "projectPacman/Pacman/Pacman.hpp"


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
        void wipeObject(const uint8_t,const uint8_t);

        GameField mField_;
        Keybord mKeybord_;
        Pacman mPacman_;
};

#endif // MANAGER_HPP
