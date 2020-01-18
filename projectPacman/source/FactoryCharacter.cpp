#include "projectPacman/headers/FactoryCharacter.hpp"
#include "projectPacman/headers/Pacman.hpp"
#include "projectPacman/headers/Ghost.hpp"

//------------------------------------------------------------------------------------------
CHARACTER CharacterFactory::createPacman()
//------------------------------------------------------------------------------------------
{
    return  std::make_shared<Pacman>(PACMAN_SYMBOL());
}

//------------------------------------------------------------------------------------------
CHARACTER CharacterFactory::createBlinky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(BLINKY_SYMBOL());
}
