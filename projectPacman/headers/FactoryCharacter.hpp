#ifndef FACTORY_CHARACTER_HPP
#define FACTORY_CHARACTER_HPP

#include "projectPacman/headers/IFactoryCharacter.hpp"

class CharacterFactory : public ICharacterFactory {
    public:
        virtual CHARACTER createPacman()override;
        virtual GHOST createBlinky()override;
};

#endif // FACTORY_CHARACTER_HPP
