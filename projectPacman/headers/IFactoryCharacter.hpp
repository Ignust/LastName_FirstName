#ifndef IFACTORY_CHARACTER_HPP
#define IFACTORY_CHARACTER_HPP

#include "projectPacman/headers/tools/Types.hpp"

class ICharacterFactory {
    public:
        virtual T_Character createPacman() = 0;
        virtual T_Character createBlinky() = 0;
        virtual T_Character createPinky() = 0;
        virtual T_Character createInky() = 0;
        virtual T_Character createClyde() = 0;
};

#endif // IFACTORY_CHARACTER_HPP
