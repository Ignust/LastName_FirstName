#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "projectPacman/headers/tools/Types.hpp"


class ICharacter {
    public:
        ICharacter(){}
        virtual ~ICharacter(){}

        virtual void resetPosition() = 0;
        virtual Coordinates getCoordinates()const = 0;
        virtual void goUp() = 0;
        virtual void goLeft() = 0;
        virtual void goDown() = 0;
        virtual void goRight() = 0;
        virtual void goTunnel(const E_TUNNEL tunnel) = 0;
        virtual const uint8_t& getPrintSymbol()const = 0;
        virtual const uint8_t& getTileInMyPosition() = 0;
        virtual void setTileInMyPosition(const uint8_t) = 0;
        virtual void makeMove(const bool, const bool, const bool, const bool) = 0;

    private:

};

#endif // ICHARACTER_HPP
