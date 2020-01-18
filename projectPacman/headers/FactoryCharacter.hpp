#ifndef FACTORY_CHARACTER_HPP
#define FACTORY_CHARACTER_HPP

#include "projectPacman/headers/IFactoryCharacter.hpp"

class CharacterFactory : public ICharacterFactory {
    public:
        virtual Character createPacman()override;
        virtual Character createBlinky()override;
};

#endif // FACTORY_CHARACTER_HPP
