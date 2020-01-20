#ifndef GHOST_HPP
#define GHOST_HPP

#include "projectPacman/headers/ICharacter.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Ghost: public ICharacter {
    public:

        Ghost(uint8_t printSymbol);
        virtual ~Ghost();

        virtual void resetPosition()override;
        virtual const T_Coordinates& getCoordinates()const override;
        virtual void goUp()override;
        virtual void goLeft()override;
        virtual void goDown()override;
        virtual void goRight()override;
        virtual void goTunnel(const E_TUNNEL tunnel)override;
        virtual const uint8_t& getPrintSymbol()const override;
        virtual const uint8_t& getTileInMyPosition()override;
        virtual void setTileInMyPosition(const uint8_t)override;
        virtual void makeMove(const bool canGoUp, const bool canGoDown, const bool canGoLeft, const bool canGoRight)override;

    private:
        void changeCoordinateForDirection(E_DIRECTION dir);
        E_DIRECTION getNewDirectionForUp(const bool canGoUp, const bool canGoLeft, const bool canGoRight);
        E_DIRECTION getNewDirectionForDown(const bool canGoDown, const bool canGoLeft, const bool canGoRight);
        E_DIRECTION getNewDirectionForLeft(const bool canGoUp, const bool canGoDown, const bool canGoLeft);
        E_DIRECTION getNewDirectionForRight(const bool canGoUp, const bool canGoDown, const bool canGoRight);
        E_DIRECTION randomLeftRight();
        E_DIRECTION randomUpDown();

        CharacterDescription mDescription_;

};

#endif // GHOST_HPP
