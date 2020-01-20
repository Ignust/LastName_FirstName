#ifndef FACTORY_CHARACTER_HPP
#define FACTORY_CHARACTER_HPP

#include "projectPacman/headers/IFactoryCharacter.hpp"

class CharacterFactory : public ICharacterFactory {
    public:
        virtual T_Character createPacman()override;
        virtual T_Character createBlinky()override;
        virtual T_Character createPinky()override;
        virtual T_Character createInky()override;
        virtual T_Character createClyde()override;
};

#endif // FACTORY_CHARACTER_HPP
