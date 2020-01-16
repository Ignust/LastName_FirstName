#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "projectPacman/headers/ICharacter.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Pacman: public ICharacter {
    public:
        Pacman();
        virtual ~Pacman();

        virtual bool move();
        virtual void resetPosition();
        virtual COORDINATES getCoordinates()const;
        virtual void goUp();
        virtual void goLeft();
        virtual void goDown();
        virtual void goRight();
        virtual void setNextTile(uint8_t);
        virtual COORDINATES getNextTileCoordinates();
        virtual void goTunnel(const E_TUNNEL tunnel);
        virtual uint8_t getPrintSymbol()const;

        private:
        CharacterDescription mDescription_;


};

#endif // PACMAN_HPP
