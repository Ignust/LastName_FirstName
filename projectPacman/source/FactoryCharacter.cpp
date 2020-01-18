#include "projectPacman/headers/FactoryCharacter.hpp"
#include "projectPacman/headers/Pacman.hpp"
#include "projectPacman/headers/Ghost.hpp"

//------------------------------------------------------------------------------------------
Character CharacterFactory::createPacman()
//------------------------------------------------------------------------------------------
{
    return  std::make_shared<Pacman>(PACMAN_SYMBOL());
}

//------------------------------------------------------------------------------------------
Character CharacterFactory::createBlinky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(BLINKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
Character CharacterFactory::createPinky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(PINKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
Character CharacterFactory::createInky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(INKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
Character CharacterFactory::createClyde()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(CLYDE_SYMBOL());
}
