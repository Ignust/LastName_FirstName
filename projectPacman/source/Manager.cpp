#include<thread>
#include <istream>

#include "projectPacman/headers/Manager.hpp"
#include "projectPacman/headers/FactoryCharacter.hpp"

//------------------------------------------------------------------------------------------
Manager::Manager()
    : mField_(),
      mKeybord_(),
      mPacman_(FactoryCharacter::create(E_CHARACTER::PACMAN)),
      mScore_(INIT_SCORE()),
      mLives_(INIT_LIVES()),
      mSmallPoints_(SMALLPOINT_AMOUNT()),
      mMazeLevel_(INIT_MAZE_LEVEL()),
      mGameOver_(false),
      mBlinky_(FactoryCharacter::create(E_CHARACTER::BLINKY))
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
    //std::this_thread::sleep_for(std::chrono::milliseconds(30));
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
    mScore_ = {INIT_SCORE()};//INIT_SCORE();
    mGameOver_ = false;
}

//------------------------------------------------------------------------------------------
void Manager::processingPressedButton()
//------------------------------------------------------------------------------------------
{
    switch (mKeybord_.getButtons()) {
    case A_Button:
    case Left_Button:
        CharacterGoLeft(mPacman_);
        break;
    case D_Button:
    case Right_Button:
        CharacterGoRight(mPacman_);
        break;
    case S_Button:
    case Down_Button:
        CharacterGoDown(mPacman_);
        break;
    case W_Button:
    case UP_Button:
        CharacterGoUp(mPacman_);
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------------------
void Manager::wipeObject(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    mField_.setChar(character->getCoordinates(),character->getTileInMyPosition());
}

//------------------------------------------------------------------------------------------
void Manager::checkScore()
//------------------------------------------------------------------------------------------
{
    if (mField_.getChar(mPacman_->getCoordinates()) == SMALLPOINT_SYMBOL) {
        mScore_ += SMALLPOINT_SCORE();
        mField_.printScore(mScore_);
        mSmallPoints_--;
        //std::cout << static_cast<int>(mSmallPoints_) << " ";
    }
    if (mField_.getChar(mPacman_->getNextTileCoordinates()) == ENERGIZER_SYMBOL) {
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
bool Manager::checkRotation(const COORDINATES& rotation)
//------------------------------------------------------------------------------------------
{
    return mField_.getChar(rotation) != BOUNDARY_SYMBOL;
}

//------------------------------------------------------------------------------------------
void Manager::nextLevel()
//------------------------------------------------------------------------------------------
{
    mMazeLevel_++;
    if (mMazeLevel_ > MAZE_LEVEL_AMOUNT()){
        mGameOver_ = true;
        return;
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
void Manager::CharacterGoLeft(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    COORDINATES rotation(character->getCoordinates());
    rotation.first--;
    if (checkRotation(rotation)) {
        character->goLeft();
    }
}

//------------------------------------------------------------------------------------------
void Manager::CharacterGoRight(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    COORDINATES rotation(character->getCoordinates());
    rotation.first++;
    if (checkRotation(rotation)) {
        character->goRight();
    }
}

//------------------------------------------------------------------------------------------
void Manager::CharacterGoDown(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    COORDINATES rotation(character->getCoordinates());
    rotation.second++;
    if (checkRotation(rotation)) {
        character->goDown();
    }
}

//------------------------------------------------------------------------------------------
void Manager::CharacterGoUp(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    COORDINATES rotation(character->getCoordinates());
    rotation.second--;
    if (checkRotation(rotation)) {
        character->goUp();
    }
}

//------------------------------------------------------------------------------------------
void Manager::updatePacman()
//------------------------------------------------------------------------------------------
{
    updateCharacterDirection(mPacman_);
    wipeObject(mPacman_);
    if (mPacman_->move()) {
        checkCollisionWithCharacters(mPacman_);
        checkScore();
        checkTunnel();
    }
    drawCharacter(mPacman_);
}

//------------------------------------------------------------------------------------------
void Manager::updateGhosts()
//------------------------------------------------------------------------------------------
{

    //drawCharacter(mBlinky_);

    updateCharacterDirection(mBlinky_);
    wipeObject(mBlinky_);
    mBlinky_->goLeft();
    if (mBlinky_->move()) {
        checkCollisionWithCharacters(mBlinky_);
    }
    drawCharacter(mBlinky_);
}

//------------------------------------------------------------------------------------------
void Manager::drawCharacter(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    if (character->getPrintSymbol() != PACMAN_SYMBOL) {
        character->setTileInMyPosition(mField_.getChar(character->getCoordinates()));
    }
    mField_.setChar(character->getCoordinates(), character->getPrintSymbol());
}

//------------------------------------------------------------------------------------------
void Manager::updateCharacterDirection(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    character->setNextTile(mField_.getChar(character->getNextTileCoordinates()));
}

//------------------------------------------------------------------------------------------
void Manager::checkCollisionWithCharacters(CHARACTER character)
//------------------------------------------------------------------------------------------
{
    if (character->getPrintSymbol() == PACMAN_SYMBOL) {
        if (mField_.getChar(character->getCoordinates()) == BLINKY_SYMBOL) {
            decrementLives();
        }
    } else {

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

