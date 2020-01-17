#ifndef GHOST_HPP
#define GHOST_HPP

#include "projectPacman/headers/ICharacter.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Ghost: public ICharacter {
    public:
        Ghost(uint8_t printSymbol);
        virtual ~Ghost();

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
         uint8_t getTileInMyPosition()override;
         void setTileInMyPosition(const uint8_t)override;

        private:
         void changeDirection();

        CharacterDescription mDescription_;

};

#endif // GHOST_HPP
