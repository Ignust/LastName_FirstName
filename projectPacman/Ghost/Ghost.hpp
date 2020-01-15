#ifndef GHOST_HPP
#define GHOST_HPP

#include "projectPacman/ICharacter/ICharacter.hpp"
#include "projectPacman/Tools/CharacterDescription.hpp"

class Ghost: public ICharacter {
    public:
        Ghost(uint8_t printSymbol);
        virtual ~Ghost();

        virtual bool move();
        virtual void resetPosition();
        virtual COORDINATES getCoordinates();
        virtual void goUp();
        virtual void goLeft();
        virtual void goDown();
        virtual void goRight();
        virtual void setNextTile(uint8_t);
        virtual COORDINATES getNextTileCoordinates();
        virtual void goTunnel(const E_TUNNEL tunnel);
        virtual uint8_t getPrintSymbol();

        private:
        CharacterDescription mDescription_;


};

#endif // GHOST_HPP
