TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -static
QMAKE_LFLAGS += -static-libgcc
QMAKE_LFLAGS += -static-libstdc++

SOURCES += \
        main.cpp \
        projectPacman/source/FactoryCharacter.cpp \
        projectPacman/source/GameField.cpp \
        projectPacman/source/Ghost.cpp \
        projectPacman/source/Keybord.cpp \
        projectPacman/source/Manager.cpp \
        projectPacman/source/Pacman.cpp \
        projectPacman/source/PacmanMachine.cpp \
        projectPacman/source/Timer.cpp

HEADERS += \
    projectPacman/headers/FactoryCharacter.hpp \
    projectPacman/headers/GameField.hpp \
    projectPacman/headers/Ghost.hpp \
    projectPacman/headers/ICharacter.hpp \
    projectPacman/headers/IFactoryCharacter.hpp \
    projectPacman/headers/Keybord.hpp \
    projectPacman/headers/Manager.hpp \
    projectPacman/headers/Pacman.hpp \
    projectPacman/headers/PacmanMachine.hpp \
    projectPacman/headers/Timer.hpp \
    projectPacman/headers/tools/CharacterDescription.hpp \
    projectPacman/headers/tools/Types.hpp
