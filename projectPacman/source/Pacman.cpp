#include "projectPacman/headers/Pacman.hpp"

//------------------------------------------------------------------------------------------
Pacman::Pacman(uint8_t printSymbol)
    : mDescription_()
//------------------------------------------------------------------------------------------
{
    mDescription_.mPrintSymbol_= printSymbol;
    resetPosition();
}

//------------------------------------------------------------------------------------------
Pacman::~Pacman()
//------------------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------------------
bool Pacman::move()
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
    } else
        return false;
}

//------------------------------------------------------------------------------------------
void Pacman::resetPosition()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = RIGHT;
    mDescription_.nextTile_ = OBJECT_EMPTY();
    mDescription_.mCoordinates_.first = START_X_PACMAN();
    mDescription_.mCoordinates_.second = START_Y_PACMAN();
    mDescription_.tileInMyPosition = OBJECT_EMPTY();
}

//------------------------------------------------------------------------------------------
COORDINATES Pacman::getCoordinates()const
//------------------------------------------------------------------------------------------
{
    return mDescription_.mCoordinates_;
}

//------------------------------------------------------------------------------------------
void Pacman::goUp()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = UP;
}

//------------------------------------------------------------------------------------------
void Pacman::goLeft()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = LEFT;
}

//------------------------------------------------------------------------------------------
void Pacman::goDown()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = DOWN;
}

//------------------------------------------------------------------------------------------
void Pacman::goRight()
//------------------------------------------------------------------------------------------
{
    mDescription_.mDirection_ = RIGHT;
}

//------------------------------------------------------------------------------------------
void Pacman::setNextTile(const uint8_t taile)
//------------------------------------------------------------------------------------------
{
    mDescription_.nextTile_ = taile;
}

//------------------------------------------------------------------------------------------
COORDINATES Pacman::getNextTileCoordinates()
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
void Pacman::goTunnel(const E_TUNNEL tunnel)
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
uint8_t Pacman::getPrintSymbol()const
//------------------------------------------------------------------------------------------
{
    return mDescription_.mPrintSymbol_;
}

//------------------------------------------------------------------------------------------
uint8_t Pacman::getTileInMyPosition()
//------------------------------------------------------------------------------------------
{
    return mDescription_.tileInMyPosition;
}

//------------------------------------------------------------------------------------------
void Pacman::setTileInMyPosition(const uint8_t tiele)
//------------------------------------------------------------------------------------------
{
    mDescription_.tileInMyPosition = tiele;
}

//------------------------------------------------------------------------------------------
void Pacman::makeMove(const bool canGoUp, const bool canGoDown, const bool canGoLeft, const bool canGoRight)
//------------------------------------------------------------------------------------------
{
    if (canGoUp && mDescription_.mDirection_ == UP) {
        mDescription_.mCoordinates_.second--;
    } else if (canGoDown && mDescription_.mDirection_ == DOWN) {
        mDescription_.mCoordinates_.second++;
    } else if (canGoLeft && mDescription_.mDirection_ == LEFT) {
        mDescription_.mCoordinates_.first--;
    } else if (canGoRight && mDescription_.mDirection_ == RIGHT) {
        mDescription_.mCoordinates_.first++;
    }
}


