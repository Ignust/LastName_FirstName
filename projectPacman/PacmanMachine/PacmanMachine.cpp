#include <iostream>
#include <windows.h>

#include "PacmanMachine.hpp"

//------------------------------------------------------------------------------------------
PacmanMachine::PacmanMachine()
    : mManager_(),
      mDatabase_()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
PacmanMachine::~PacmanMachine()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void PacmanMachine::run()
//------------------------------------------------------------------------------------------
{
    showMenu();
}

//------------------------------------------------------------------------------------------
void PacmanMachine::showMenu()
//------------------------------------------------------------------------------------------
{
    int selectOption = 0;
    std::cout << "1. Start Game \n"
                 "2. Show Statistics \n"
                 "3. Quit\n\n\n"
                 "Select option:" << std::endl;
    std::cin >>  selectOption;
    system("cls");
    switch (selectOption) {
        case 1 :
            startGame();
            break;
        case 2 :
            showStatistics();
            break;
        case 3 :
            QuitProgram();
            break;
        default:
            std::cout << "invalid option" << std::endl;
            system("pause");
            system("cls");
            showMenu();
            break;
    }

}

//------------------------------------------------------------------------------------------
void PacmanMachine::startGame()
//------------------------------------------------------------------------------------------
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    mManager_.showField();
    while (!mManager_.gameOver()) {
        mManager_.checkUserAction();
        mManager_.update();
    }
}

//------------------------------------------------------------------------------------------
void PacmanMachine::showStatistics()
//------------------------------------------------------------------------------------------
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

//------------------------------------------------------------------------------------------
void PacmanMachine::addPlayerToDatatbase()
//------------------------------------------------------------------------------------------
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

//------------------------------------------------------------------------------------------
void PacmanMachine::QuitProgram()
//------------------------------------------------------------------------------------------
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    exit(0);
}

