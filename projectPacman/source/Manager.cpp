#include<thread>
#include <istream>

#include "projectPacman/headers/Manager.hpp"
#include "projectPacman/headers/FactoryCharacter.hpp"

//------------------------------------------------------------------------------------------
Manager::Manager()
    : mField_(),
      mKeybord_(),
      mPacman_(),
      mScore_(INIT_SCORE()),
      mLives_(INIT_LIVES()),
      mSmallPoints_(SMALLPOINT_AMOUNT()),
      mMazeLevel_(INIT_MAZE_LEVEL()),
      mGameOver_(false),
      mBlinky_(),
      mPinky_()
//------------------------------------------------------------------------------------------
{
    CharacterFactory factory;
    mPacman_= factory.createPacman();
    mBlinky_ = factory.createBlinky();
    mPinky_ = factory.createPinky();
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
    if (mSmallPoints_ > 0) {
        updatePacman();
        updateGhosts();
    } else {
        nextLevel();
    }
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
    return mGameOver_;
}

//------------------------------------------------------------------------------------------
void Manager::resetGame()
//------------------------------------------------------------------------------------------
{
    resetLevel();
    mLives_ = INIT_LIVES();
    mMazeLevel_ = INIT_MAZE_LEVEL();
    mScore_ = {INIT_SCORE()};
    mGameOver_ = false;
}

//------------------------------------------------------------------------------------------
void Manager::processingPressedButton()
//------------------------------------------------------------------------------------------
{
    switch (mKeybord_.getButtons()) {
    case A_Button:
    case Left_Button:
        characterGoLeft(mPacman_);
        break;
    case D_Button:
    case Right_Button:
        characterGoRight(mPacman_);
        break;
    case S_Button:
    case Down_Button:
        characterGoDown(mPacman_);
        break;
    case W_Button:
    case UP_Button:
        characterGoUp(mPacman_);
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------------------
void Manager::wipeObject(const Character& character)
//------------------------------------------------------------------------------------------
{
    if(character != nullptr){
        mField_.setChar(character->getCoordinates(),character->getTileInMyPosition());
    }
}

//------------------------------------------------------------------------------------------
void Manager::checkScore()
//------------------------------------------------------------------------------------------
{
    if (mField_.getChar(mPacman_->getCoordinates()) == SMALLPOINT_SYMBOL()) {
        mScore_ += SMALLPOINT_SCORE();
        mField_.printScore(mScore_);
        mSmallPoints_--;
    }
    if (mField_.getChar(mPacman_->getCoordinates()) == ENERGIZER_SYMBOL()) {
        mScore_ += ENERGIZER_SCORE();
        mField_.printScore(mScore_);
    }
}

//------------------------------------------------------------------------------------------
void Manager::checkTunnel()
//------------------------------------------------------------------------------------------
{
    uint8_t x = mPacman_->getCoordinates().first;
    uint8_t y = mPacman_->getCoordinates().second;
    if (x == TUNNEL_1_X() && y == TUNNEL_1_Y()) {
        mPacman_->goTunnel(TUNNEL_1);
    }
    if (x == TUNNEL_2_X() && y == TUNNEL_2_Y()) {
        mPacman_->goTunnel(TUNNEL_2);
    }
}

//------------------------------------------------------------------------------------------
bool Manager::checkRotation(const Coordinates& rotation)
//------------------------------------------------------------------------------------------
{
    return mField_.getChar(rotation) != BOUNDARY_SYMBOL();
}

//------------------------------------------------------------------------------------------
void Manager::nextLevel()
//------------------------------------------------------------------------------------------
{
    mMazeLevel_++;
    if (mMazeLevel_ > MAZE_LEVEL_AMOUNT()){
        mGameOver_ = true;
    }

    resetLevel();
}

//------------------------------------------------------------------------------------------
void Manager::resetLevel()
//------------------------------------------------------------------------------------------
{
    wipeObject(mPacman_);
    wipeObject(mBlinky_);
    mField_.resetField();
    mField_.showField();
    mPacman_->resetPosition();
    mBlinky_->resetPosition();
    mSmallPoints_ = SMALLPOINT_AMOUNT();
}

//------------------------------------------------------------------------------------------
void Manager::characterGoLeft(const Character& character)
//------------------------------------------------------------------------------------------
{
    Coordinates rotation(character->getCoordinates());
    rotation.first--;
    if (checkRotation(rotation)) {
        character->goLeft();
    }
}

//------------------------------------------------------------------------------------------
void Manager::characterGoRight(const Character& character)
//------------------------------------------------------------------------------------------
{
    Coordinates rotation(character->getCoordinates());
    rotation.first++;
    if (checkRotation(rotation)) {
        character->goRight();
    }
}

//------------------------------------------------------------------------------------------
void Manager::characterGoDown(const Character& character)
//------------------------------------------------------------------------------------------
{
    Coordinates rotation(character->getCoordinates());
    rotation.second++;
    if (checkRotation(rotation)) {
        character->goDown();
    }
}

//------------------------------------------------------------------------------------------
void Manager::characterGoUp(const Character& character)
//------------------------------------------------------------------------------------------
{
    Coordinates rotation(character->getCoordinates());
    rotation.second--;
    if (checkRotation(rotation)) {
        character->goUp();
    }
}

//------------------------------------------------------------------------------------------
void Manager::updatePacman()
//------------------------------------------------------------------------------------------
{

    Coordinates PacmanCoor = mPacman_->getCoordinates();

    bool canGoUp = (BOUNDARY_SYMBOL() != mField_.getChar(PacmanCoor.first,PacmanCoor.second - 1));
    bool canGoDown = (BOUNDARY_SYMBOL() != mField_.getChar(PacmanCoor.first,PacmanCoor.second +1));
    bool canGoLeft = (BOUNDARY_SYMBOL() != mField_.getChar(PacmanCoor.first - 1,PacmanCoor.second));
    bool canGoRight = (BOUNDARY_SYMBOL() != mField_.getChar(PacmanCoor.first + 1,PacmanCoor.second));

    wipeObject(mPacman_);
    mPacman_->makeMove(canGoUp, canGoDown, canGoLeft, canGoRight);
    checkCollisionWithCharacters(mPacman_);
    checkScore();
    checkTunnel();
    drawCharacter(mPacman_);
}

//------------------------------------------------------------------------------------------
void Manager::updateGhosts()
//------------------------------------------------------------------------------------------
{
    updateBlinky();
    //updatePinky();

}

//------------------------------------------------------------------------------------------
void Manager::drawCharacter(const Character& character)
//------------------------------------------------------------------------------------------
{
    if (character->getPrintSymbol() != PACMAN_SYMBOL()) {
        character->setTileInMyPosition(mField_.getChar(character->getCoordinates()));
    }
    mField_.setChar(character->getCoordinates(), character->getPrintSymbol());
}

//------------------------------------------------------------------------------------------
void Manager::checkCollisionWithCharacters(const Character& character)
//------------------------------------------------------------------------------------------
{
    if (character->getPrintSymbol() == PACMAN_SYMBOL()) {
        if (mField_.getChar(character->getCoordinates()) == BLINKY_SYMBOL()) {
            decrementLives();
        }
    } else {
        if (mField_.getChar(character->getCoordinates()) == PACMAN_SYMBOL()) {
            decrementLives();
            character->setTileInMyPosition(OBJECT_EMPTY());
        }
    }
}

//------------------------------------------------------------------------------------------
void Manager::decrementLives()
//------------------------------------------------------------------------------------------
{
    mLives_--;
    mField_.printLives(mLives_);
    if (!mLives_){
        mGameOver_ = true;
    }
    resetLevel();
}

//------------------------------------------------------------------------------------------
void Manager::updateBlinky()
//------------------------------------------------------------------------------------------
{
    Coordinates BlinkyCoor = mBlinky_->getCoordinates();

    bool canGoUp = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first,BlinkyCoor.second - 1));
    bool canGoDown = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first,BlinkyCoor.second +1));
    bool canGoLeft = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first - 1,BlinkyCoor.second));
    bool canGoRight = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first + 1,BlinkyCoor.second));

    wipeObject(mBlinky_);
    mBlinky_->makeMove(canGoUp, canGoDown, canGoLeft, canGoRight);
    checkCollisionWithCharacters(mBlinky_);
    drawCharacter(mBlinky_);
}

//------------------------------------------------------------------------------------------
void Manager::updatePinky()
//------------------------------------------------------------------------------------------
{
    Coordinates BlinkyCoor = mPinky_->getCoordinates();

    bool canGoUp = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first,BlinkyCoor.second - 1));
    bool canGoDown = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first,BlinkyCoor.second +1));
    bool canGoLeft = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first - 1,BlinkyCoor.second));
    bool canGoRight = (BOUNDARY_SYMBOL() != mField_.getChar(BlinkyCoor.first + 1,BlinkyCoor.second));

    wipeObject(mPinky_);
    mPinky_->makeMove(canGoUp, canGoDown, canGoLeft, canGoRight);
    checkCollisionWithCharacters(mPinky_);
    drawCharacter(mPinky_);
}




