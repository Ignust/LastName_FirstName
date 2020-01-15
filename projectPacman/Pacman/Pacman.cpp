#include "Pacman.hpp"

//------------------------------------------------------------------------------------------
Pacman::Pacman()
    : mDescription_()
//------------------------------------------------------------------------------------------
{
    mDescription_.mPrintSymbol_= PACMAN_SYMBOL;
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
    if (mDescription_.nextTile_ != BOUNDARY_SYMBOL) {
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
    mDescription_.nextTile_ = OBJECT_EMPTY;
    mDescription_.mCoordinates_.first = START_X_PACMAN;
    mDescription_.mCoordinates_.second = START_Y_PACMAN;
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
void Pacman::setNextTile(uint8_t taile)
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
        mDescription_.mCoordinates_.first = TUNNEL_2_X;
        mDescription_.mCoordinates_.second = TUNNEL_2_Y;
    }
    if (tunnel == TUNNEL_2) {
        mDescription_.mCoordinates_.first = TUNNEL_1_X;
        mDescription_.mCoordinates_.second = TUNNEL_1_Y;
    }
}

//------------------------------------------------------------------------------------------
uint8_t Pacman::getPrintSymbol()const
//------------------------------------------------------------------------------------------
{
    return mDescription_.mPrintSymbol_;
}




