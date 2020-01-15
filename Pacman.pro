TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -static
QMAKE_LFLAGS += -static-libgcc
QMAKE_LFLAGS += -static-libstdc++

SOURCES += \
        main.cpp \
        projectPacman/Database/Database.cpp \
        projectPacman/GameField/GameField.cpp \
        projectPacman/Ghost/Ghost.cpp \
        projectPacman/ICharacter/ICharacter.cpp \
        projectPacman/Keybord/Keybord.cpp \
        projectPacman/Manager/Manager.cpp \
        projectPacman/Pacman/Pacman.cpp \
        projectPacman/PacmanMachine/PacmanMachine.cpp \
        projectPacman/Timer/Timer.cpp

HEADERS += \
    projectPacman/Database/Database.hpp \
    projectPacman/GameField/GameField.hpp \
    projectPacman/Ghost/Ghost.hpp \
    projectPacman/ICharacter/ICharacter.hpp \
    projectPacman/Keybord/Keybord.hpp \
    projectPacman/Manager/Manager.hpp \
    projectPacman/Pacman/Pacman.hpp \
    projectPacman/PacmanMachine/PacmanMachine.hpp \
    projectPacman/Timer/Timer.hpp \
    projectPacman/Tools/CharacterDescription.hpp \
    projectPacman/Tools/Types.hpp
