#ifndef GHOST_HPP
#define GHOST_HPP

#include "projectPacman/headers/IGhost.hpp"
#include "projectPacman/headers/tools/CharacterDescription.hpp"

class Ghost: public IGhost {
    public:

        Ghost(uint8_t printSymbol);
        virtual ~Ghost();

        virtual bool move()override;
        virtual void resetPosition()override;
        virtual COORDINATES getCoordinates()const override;
        virtual void goUp()override;
        virtual void goLeft()override;
        virtual void goDown()override;
        virtual void goRight()override;
        virtual void setNextTile(const uint8_t)override;
        virtual COORDINATES getNextTileCoordinates()override;
        virtual void goTunnel(const E_TUNNEL tunnel)override;
        virtual uint8_t getPrintSymbol()const override;
        virtual uint8_t getTileInMyPosition()override;
        virtual void setTileInMyPosition(const uint8_t)override;
        virtual void toDo() override{};

    private:
        void changeDirection();

        CharacterDescription mDescription_;

};

#endif // GHOST_HPP
