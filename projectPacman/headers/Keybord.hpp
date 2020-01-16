#ifndef KAYBORD_HPP
#define KAYBORD_HPP

#include<cstdint>

class Keybord {
    public:
        Keybord();
        ~Keybord();
        bool checkButtons();
        uint32_t getButtons();

    private:

};

#endif // KAYBORD_HPP
