#include<thread>
#include <istream>

#include "Manager.hpp"

//------------------------------------------------------------------------------------------
Manager::Manager()
    : mField_(),
      mKeybord_(),
      mPacman_(),
      mScore_(0),
      mLives_(INIT_LIVES)
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
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
    wipeObject(mPacman_.getCoordinates());
    if (mPacman_.move()) {
        checkScore();
        checkTunnel();
        updatePacmanDirection();
    }
    drawPacman();
}

//------------------------------------------------------------------------------------------
void Manager::showField()
//------------------------------------------------------------------------------------------
{
    mField_.printScore(mScore_);
    mField_.printLives(mLives_);
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
    COORDINATES rotation(mPacman_.getCoordinates());
    switch (mKeybord_.getButtons()) {
    case A_Button:
    case Left_Button:
        rotation.first--;
        if (checkRotation(rotation)) {
            mPacman_.goLeft();
            updatePacmanDirection();
        }
        break;
    case D_Button:
    case Right_Button:
        rotation.first++;
        if (checkRotation(rotation)) {
            mPacman_.goRight();
            updatePacmanDirection();
        }
        break;
    case S_Button:
    case Down_Button:
        rotation.second++;
        if (checkRotation(rotation)) {
            mPacman_.goDown();
            updatePacmanDirection();
        }
        break;
    case W_Button:
    case UP_Button:
        rotation.second--;
        if (checkRotation(rotation)) {
            mPacman_.goUp();
            updatePacmanDirection();
        }
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

//------------------------------------------------------------------------------------------
void Manager::checkTunnel()
//------------------------------------------------------------------------------------------
{
    uint8_t x = mPacman_.getCoordinates().first;
    uint8_t y = mPacman_.getCoordinates().second;
    if (x == TUNNEL_1_X && y == TUNNEL_1_Y) {
        mPacman_.goTunnel(TUNNEL_1);
    }
    if (x == TUNNEL_2_X && y == TUNNEL_2_Y) {
        mPacman_.goTunnel(TUNNEL_2);
    }
}

//------------------------------------------------------------------------------------------
bool Manager::checkRotation(const COORDINATES rotation)
//------------------------------------------------------------------------------------------
{
    if (mField_.getChar(rotation) != BOUNDARY_SYMBOL) {
        return true;
    }
    return  false;
}

