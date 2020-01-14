#include <iostream>
#include <windows.h>
#include <thread>

#include "PacmanMachine.hpp"
#include <projectPacman/Timer/Timer.hpp>

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
    showMenu();
}

//------------------------------------------------------------------------------------------
void PacmanMachine::startGame()
//------------------------------------------------------------------------------------------
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    utils::Timer timer;


    mManager_.showField();
    system("pause");
    timer.start(std::chrono::milliseconds(40),[this](){ mManager_.update();});
    while (!mManager_.gameOver()) {
        mManager_.checkUserAction();
        //mManager_.update();
    }
    timer.stop();
    mManager_.resetGame();

    system("cls");
    std::cout << "GAME OVER" << std::endl;
    system("pause");
    system("cls");
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

