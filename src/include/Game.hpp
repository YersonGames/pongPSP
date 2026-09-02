#pragma once
#include <pspctrl.h>

#include "Player.hpp"

class Game
{
    public:
        Game();
        void Update(SceCtrlData& pad);
        void Draw();

    private:
        Player player;
};