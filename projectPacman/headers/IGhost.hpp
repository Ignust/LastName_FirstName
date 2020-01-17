#ifndef IGHOST_HPP
#define IGHOST_HPP

#include "projectPacman/headers/ICharacter.hpp"

class IGhost: public ICharacter {
    public:
        IGhost(){}
        virtual ~IGhost(){}

        virtual void toDo() = 0;

};

#endif // IGHOST_HPP
