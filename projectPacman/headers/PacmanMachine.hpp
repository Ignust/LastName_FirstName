#ifndef PACMANMACHINE_HPP
#define PACMANMACHINE_HPP

#include "projectPacman/headers/Manager.hpp"

class PacmanMachine {
    public:
        PacmanMachine();
        ~PacmanMachine();

        void run();

    private:
        void showMenu();
        void startGame();
        void showStatistics();
        void addPlayerToDatatbase();
        void QuitProgram();

        Manager mManager_;
        //Database mDatabase_;

};

#endif // PACMANMACHINE_HPP
