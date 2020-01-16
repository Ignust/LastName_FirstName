#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "projectPacman/headers/ICharacter.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Pacman: public ICharacter {
    public:
        Pacman();
        virtual ~Pacman();

        bool move()override;
        void resetPosition()override;
        COORDINATES getCoordinates()const override;
        void goUp()override;
        void goLeft()override;
        void goDown()override;
        void goRight()override;
        void setNextTile(uint8_t)override;
        COORDINATES getNextTileCoordinates()override;
        void goTunnel(const E_TUNNEL tunnel)override;
        uint8_t getPrintSymbol()const override;

        private:
        CharacterDescription mDescription_;


};

#endif // PACMAN_HPP
