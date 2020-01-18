#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "projectPacman/headers/ICharacter.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Pacman: public ICharacter {
    public:
        Pacman(uint8_t printSymbol);
        virtual ~Pacman();

        virtual void resetPosition()override;
        virtual Coordinates getCoordinates()const override;
        virtual void goUp()override;
        virtual void goLeft()override;
        virtual void goDown()override;
        virtual void goRight()override;
        virtual void goTunnel(const E_TUNNEL tunnel)override;
        virtual uint8_t getPrintSymbol()const override;
        virtual uint8_t getTileInMyPosition()override;
        virtual void setTileInMyPosition(const uint8_t)override;
        virtual void makeMove(const bool canGoUp, const bool canGoDown, const bool canGoLeft, const bool canGoRight)override;

        private:
        CharacterDescription mDescription_;


};

#endif // PACMAN_HPP
