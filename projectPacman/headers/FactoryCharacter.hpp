#ifndef FACTORY_CHARACTER_HPP
#define FACTORY_CHARACTER_HPP

#include "projectPacman/headers/tools/Types.hpp"
#include "projectPacman/headers/Pacman.hpp"
#include "projectPacman/headers/Ghost.hpp"
/*
enum class E_CHARACTER: uint8_t {
    PACMAN,
    BLINKY,
    PINKY,
    INKY,
    CLYDE
};

class FactoryCharacter {
    public:

        static CHARACTER create(E_CHARACTER inputName){
            CHARACTER charect;
            switch(inputName)
            {
            case E_CHARACTER::PACMAN:
                charect = std::make_shared<Pacman>(PACMAN_SYMBOL);
                break;
            case E_CHARACTER::BLINKY:
                charect = std::make_shared<Ghost>(BLINKY_SYMBOL);
                break;
            default:
                break;
            }
            //ch.init();
            return charect;
        }
};
*/
class ICharacterFactory {
    public:
        virtual CHARACTER createPacman() = 0;
        virtual CHARACTER createBlinky() = 0;
};

class CharacterFactory : public ICharacterFactory {
    public:
         CHARACTER createPacman()override{return  std::make_shared<Pacman>(PACMAN_SYMBOL());}
         CHARACTER createBlinky()override{return  std::make_shared<Ghost>(BLINKY_SYMBOL());}
};

#endif // FACTORY_CHARACTER_HPP
