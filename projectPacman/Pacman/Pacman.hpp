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
        void goUp();
        void goLeft();
        void goDown();
        void goRight();
        void setNextTile(uint8_t);

        private:
        CharacterDescription mDescription_;

};

#endif // PACMAN_HPP
