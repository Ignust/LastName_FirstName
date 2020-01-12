#include<thread>
//#include<windows.h>

#include "Manager.hpp"
#include "projectPacman/Tools/Types.hpp"

//------------------------------------------------------------------------------------------
Manager::Manager()
    : mField_(),
      mKeybord_(),
      mPacman_()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
Manager::~Manager()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
void Manager::checkUserAction()
//------------------------------------------------------------------------------------------
{
    if (mKeybord_.checkButtons()) {
        processingPressedButton();
    }
}

//------------------------------------------------------------------------------------------
void Manager::update()
//------------------------------------------------------------------------------------------
{
    wipeObject(mPacman_.getXpos(), mPacman_.getYpos());
    if (mPacman_.move()) {
        mPacman_.setNextTile(mField_.getChar(mPacman_.getXpos(), mPacman_.getYpos()));
    }
    drawPacman();
}

//------------------------------------------------------------------------------------------
void Manager::showField()
//------------------------------------------------------------------------------------------
{
    mField_.showField();
    //system("pause>nul");
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
}

//------------------------------------------------------------------------------------------
bool Manager::gameOver()
//------------------------------------------------------------------------------------------
{
    return false;
}

//------------------------------------------------------------------------------------------
void Manager::drawPacman()
//------------------------------------------------------------------------------------------
{
    mField_.setChar(mPacman_.getXpos(), mPacman_.getYpos(),PACMAN_SYMBOL);
}

//------------------------------------------------------------------------------------------
void Manager::processingPressedButton()
//------------------------------------------------------------------------------------------
{
    switch (mKeybord_.getButtons()) {
    case A_Button:
    case Left_Button:
        mPacman_.goLeft();
        break;
    case D_Button:
    case Right_Button:
        mPacman_.goRight();
        break;
    case S_Button:
    case Down_Button:
        mPacman_.goDown();
        break;
    case W_Button:
    case UP_Button:
        mPacman_.goUp();
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------------------
void Manager::wipeObject(const uint8_t x,const uint8_t y)
//------------------------------------------------------------------------------------------
{
    mField_.setChar(x, y,OBJECT_EMPTY);
}




