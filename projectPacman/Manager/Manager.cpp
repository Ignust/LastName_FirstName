#include<thread>

#include "Manager.hpp"

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
    wipeObject(mPacman_.getCoordinates());
    if (mPacman_.move()) {
        updatePacmanDirection();
    }
    drawPacman();
}

//------------------------------------------------------------------------------------------
void Manager::showField()
//------------------------------------------------------------------------------------------
{
    mField_.showField();
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
    mField_.setChar(mPacman_.getCoordinates(),PACMAN_SYMBOL);
}

//------------------------------------------------------------------------------------------
void Manager::processingPressedButton()
//------------------------------------------------------------------------------------------
{
    switch (mKeybord_.getButtons()) {
    case A_Button:
    case Left_Button:
        mPacman_.goLeft();
        updatePacmanDirection();
        break;
    case D_Button:
    case Right_Button:
        mPacman_.goRight();
        updatePacmanDirection();
        break;
    case S_Button:
    case Down_Button:
        mPacman_.goDown();
        updatePacmanDirection();
        break;
    case W_Button:
    case UP_Button:
        mPacman_.goUp();
        updatePacmanDirection();
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------------------
void Manager::wipeObject(COORDINATES coord)
//------------------------------------------------------------------------------------------
{
    mField_.setChar(coord.first, coord.second,OBJECT_EMPTY);
}

//------------------------------------------------------------------------------------------
void Manager::updatePacmanDirection()
//------------------------------------------------------------------------------------------
{
    mPacman_.setNextTile(mField_.getChar(mPacman_.getNextTileCoordinates()));
}



