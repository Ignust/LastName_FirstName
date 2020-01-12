#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "projectPacman/ICharacter/ICharacter.hpp"
#include "projectPacman/Tools/CharacterDescription.hpp"

class Pacman: public ICharacter {
    public:
        Pacman();
        virtual ~Pacman();

        virtual bool move();
        virtual void resetPosition();
        virtual uint8_t getXpos();
        virtual uint8_t getYpos();
        virtual void goUp();
        virtual void goLeft();
        virtual void goDown();
        virtual void goRight();
        virtual void setNextTile(uint8_t);
        uint8_t getNextTileXpos();
        uint8_t getNextTileYpos();

        private:
        CharacterDescription mDescription_;


};

#endif // PACMAN_HPP
