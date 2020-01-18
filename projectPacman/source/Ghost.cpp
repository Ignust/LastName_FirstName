#include <ctime>
#include <cstdlib>

#include "projectPacman/headers/Ghost.hpp"

//------------------------------------------------------------------------------------------
Ghost::Ghost(uint8_t printSymbol)
    : mDescription_()
//------------------------------------------------------------------------------------------
{
    mDescription_.mPrintSymbol_= printSymbol;
    resetPosition();
}

//------------------------------------------------------------------------------------------
Ghost::~Ghost()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
bool Ghost::move()
//------------------------------------------------------------------------------------------
{
    if (mDescription_.nextTile_ != BOUNDARY_SYMBOL()) {
        switch (mDescription_.mDirection_) {
            case UP :
                mDescription_.mCoordinates_.second--;
                break;
            case LEFT :
                mDescription_.mCoordinates_.first--;
                break;
            case DOWN :
                mDescription_.mCoordinates_.second++;
                break;
            case RIGHT :
                mDescription_.mCoordinates_.first++;
                break;
            default:
                break;
        }
        return true;
    } else {
        changeDirection();
        return false;
    }
}

//------------------------------------------------------------------------------------------
void Ghost::resetPosition()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = RIGHT;
    mDescription_.nextTile_ = OBJECT_EMPTY();
    mDescription_.mCoordinates_.first = START_X_GHOST();
    mDescription_.mCoordinates_.second = START_Y_GHOST();
    mDescription_.tileInMyPosition = OBJECT_EMPTY();
}

//------------------------------------------------------------------------------------------
COORDINATES Ghost::getCoordinates()const
//------------------------------------------------------------------------------------------
{
    return mDescription_.mCoordinates_;
}

//------------------------------------------------------------------------------------------
void Ghost::goUp()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = UP;
}

//------------------------------------------------------------------------------------------
void Ghost::goLeft()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = LEFT;
}

//------------------------------------------------------------------------------------------
void Ghost::goDown()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = DOWN;
}

//------------------------------------------------------------------------------------------
void Ghost::goRight()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = RIGHT;
}

//------------------------------------------------------------------------------------------
void Ghost::setNextTile(const uint8_t taile)
//------------------------------------------------------------------------------------------
{
    mDescription_.nextTile_ = taile;
}

//------------------------------------------------------------------------------------------
COORDINATES Ghost::getNextTileCoordinates()
//------------------------------------------------------------------------------------------
{
    COORDINATES nextTaile (mDescription_.mCoordinates_);
    if (mDescription_.mDirection_ == LEFT) {
        nextTaile.first--;
    }
    if (mDescription_.mDirection_ == RIGHT) {
        nextTaile.first++;
    }
    if (mDescription_.mDirection_ == UP) {
        nextTaile.second--;
    }
    if (mDescription_.mDirection_ == DOWN) {
        nextTaile.second++;
    }
    return nextTaile;
}

//------------------------------------------------------------------------------------------
void Ghost::goTunnel(const E_TUNNEL tunnel)
//------------------------------------------------------------------------------------------
{
    if (tunnel == TUNNEL_1) {
        mDescription_.mCoordinates_.first = TUNNEL_2_X();
        mDescription_.mCoordinates_.second = TUNNEL_2_Y();
    }
    if (tunnel == TUNNEL_2) {
        mDescription_.mCoordinates_.first = TUNNEL_1_X();
        mDescription_.mCoordinates_.second = TUNNEL_1_Y();
    }
}

//------------------------------------------------------------------------------------------
uint8_t Ghost::getPrintSymbol()const
//------------------------------------------------------------------------------------------
{
    return mDescription_.mPrintSymbol_;
}

//------------------------------------------------------------------------------------------
uint8_t Ghost::getTileInMyPosition()
//------------------------------------------------------------------------------------------
{
    return mDescription_.tileInMyPosition;
}

//------------------------------------------------------------------------------------------
void Ghost::setTileInMyPosition(const uint8_t tiele)
//------------------------------------------------------------------------------------------
{
    mDescription_.tileInMyPosition = tiele;
}

//------------------------------------------------------------------------------------------
void Ghost::makeMove(const bool canGoUp, const bool canGoDown, const bool canGoLeft, const bool canGoRight)
//------------------------------------------------------------------------------------------
{
    E_DIRECTION newDir;
    switch (mDescription_.mDirection_) {
        case UP :
            newDir = getNewDirectionForUp(canGoUp,canGoLeft, canGoRight);
            break;
        case LEFT :
            newDir = getNewDirectionForLeft(canGoUp,canGoDown, canGoLeft);
            break;
        case DOWN :
            newDir = getNewDirectionForDown(canGoDown,canGoLeft, canGoRight);
            break;
        case RIGHT :
            newDir = getNewDirectionForRight(canGoUp,canGoDown, canGoRight);
            break;
        default:
            break;
    }
    changeCoordinateForDirection(newDir);
}

//------------------------------------------------------------------------------------------
void Ghost::changeDirection()
//------------------------------------------------------------------------------------------
{
    if (mDescription_.mDirection_ == UP || DOWN) {
        switch (1 + rand()%3) {
        case 1:
            goLeft();
            break;
        case 2:
            goRight();
            break;
        }
    }
    if (mDescription_.mDirection_ == LEFT || RIGHT) {
        switch (1 + rand()%3) {
        case 1:
            goUp();
            break;
        case 2:
            goDown();
            break;
        }
    }
}

//------------------------------------------------------------------------------------------
void Ghost::changeCoordinateForDirection(E_DIRECTION dir)
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = dir;
    switch (mDescription_.mDirection_) {
        case UP :
            mDescription_.mCoordinates_.second--;
            break;
        case LEFT :
            mDescription_.mCoordinates_.first--;
            break;
        case DOWN :
            mDescription_.mCoordinates_.second++;
            break;
        case RIGHT :
            mDescription_.mCoordinates_.first++;
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::getNewDirectionForUp(const bool canGoUp, const bool canGoLeft, const bool canGoRight)
//------------------------------------------------------------------------------------------
{
    if (canGoUp) {
        return UP;
    }
    else if (canGoLeft && canGoRight) {
        return randomLeftRight();
    }
    else if (canGoLeft) {
        return LEFT;
    }
    else if (canGoRight) {
        return RIGHT;
    }
    return UP; //unreachable
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::getNewDirectionForDown(const bool canGoDown, const bool canGoLeft, const bool canGoRight)
//------------------------------------------------------------------------------------------
{
    if (canGoDown) {
        return DOWN;
    }
    else if (canGoLeft && canGoRight) {
        return randomLeftRight();
    }
    else if (canGoLeft) {
        return LEFT;
    }
    else if (canGoRight) {
        return RIGHT;
    }
    return UP; //unreachable
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::getNewDirectionForLeft(const bool canGoUp, const bool canGoDown, const bool canGoLeft)
//------------------------------------------------------------------------------------------
{
    if (canGoLeft) {
        return LEFT;
    }
    else if (canGoUp && canGoDown) {
        return randomUpDown();
    }
    else if (canGoUp) {
        return UP;
    }
    else if (canGoDown) {
        return DOWN;
    }
    return UP; //unreachable
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::getNewDirectionForRight(const bool canGoUp, const bool canGoDown, const bool canGoRight)
//------------------------------------------------------------------------------------------
{
    if (canGoRight) {
        return RIGHT;
    }
    else if (canGoUp && canGoDown) {
        return randomUpDown();
    }
    else if (canGoUp) {
        return UP;
    }
    else if (canGoDown) {
        return DOWN;
    }
    return UP; //unreachable
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::randomLeftRight()
//------------------------------------------------------------------------------------------
{
    srand(time(0));
    return (0 == ( rand() % 2 )) ? LEFT : RIGHT;
}

//------------------------------------------------------------------------------------------
E_DIRECTION Ghost::randomUpDown()
//------------------------------------------------------------------------------------------
{
    srand(time(0));
    return (0 == ( rand() % 2 )) ? UP : DOWN;
}




