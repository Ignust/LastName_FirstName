#ifndef IFACTORY_CHARACTER_HPP
#define IFACTORY_CHARACTER_HPP

#include "projectPacman/headers/tools/Types.hpp"

class ICharacterFactory {
    public:
        virtual CHARACTER createPacman() = 0;
        virtual CHARACTER createBlinky() = 0;
};

#endif // IFACTORY_CHARACTER_HPP
