#include<thread>
#include <istream>

#include "Manager.hpp"

//------------------------------------------------------------------------------------------
Manager::Manager()
    : mField_(),
      mKeybord_(),
      mPacman_(),
      mScore_(0)
//------------------------------------------------------------------------------------------
{

    //mField_.printScore(mScore_);
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
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    wipeObject(mPacman_.getCoordinates());
    if (mPacman_.move()) {
        checkScore();
        updatePacmanDirection();
    }
    drawPacman();
}

//------------------------------------------------------------------------------------------
void Manager::showField()
//------------------------------------------------------------------------------------------
{
    mField_.printScore(mScore_);
    mField_.showField();

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
    mField_.setChar(coord,OBJECT_EMPTY);
}

//------------------------------------------------------------------------------------------
void Manager::updatePacmanDirection()
//------------------------------------------------------------------------------------------
{
    mPacman_.setNextTile(mField_.getChar(mPacman_.getNextTileCoordinates()));
}

//------------------------------------------------------------------------------------------
void Manager::checkScore()
//------------------------------------------------------------------------------------------
{
    if (mField_.getChar(mPacman_.getNextTileCoordinates()) == SMALLPOINT_SYMBOL) {
        mScore_ += 10;
        mField_.printScore(mScore_);
    }
}

