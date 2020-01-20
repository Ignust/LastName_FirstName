#include "projectPacman/headers/FactoryCharacter.hpp"
#include "projectPacman/headers/Pacman.hpp"
#include "projectPacman/headers/Ghost.hpp"

//------------------------------------------------------------------------------------------
T_Character CharacterFactory::createPacman()
//------------------------------------------------------------------------------------------
{
    return  std::make_shared<Pacman>(PACMAN_SYMBOL());
}

//------------------------------------------------------------------------------------------
T_Character CharacterFactory::createBlinky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(BLINKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
T_Character CharacterFactory::createPinky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(PINKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
T_Character CharacterFactory::createInky()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(INKY_SYMBOL());
}

//------------------------------------------------------------------------------------------
T_Character CharacterFactory::createClyde()
//------------------------------------------------------------------------------------------
{
    return std::make_shared<Ghost>(CLYDE_SYMBOL());
}
