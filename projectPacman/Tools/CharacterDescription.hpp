#ifndef CHARACTERDESCRIPTION_HPP
#define CHARACTERDESCRIPTION_HPP

#include<cstdint>

enum E_DIRECTION {
     UP =       0
    , LEFT =    1
    , DOWN =    2
    , RIGHT =   3

};

struct CharacterDescription {
    E_DIRECTION mDirection_;
    uint8_t posX_;
    uint8_t posY_;
    uint8_t nextTile_;


};




#endif // CHARACTERDESCRIPTION_HPP
