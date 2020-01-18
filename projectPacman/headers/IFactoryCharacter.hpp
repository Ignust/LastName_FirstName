#ifndef IFACTORY_CHARACTER_HPP
#define IFACTORY_CHARACTER_HPP

#include "projectPacman/headers/tools/Types.hpp"

class ICharacterFactory {
    public:
        virtual Character createPacman() = 0;
        virtual Character createBlinky() = 0;
        virtual Character createPinky() = 0;
        virtual Character createInky() = 0;
        virtual Character createClyde() = 0;
};

#endif // IFACTORY_CHARACTER_HPP
