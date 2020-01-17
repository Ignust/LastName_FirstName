#include "projectPacman/headers/FactoryCharacter.hpp"

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
