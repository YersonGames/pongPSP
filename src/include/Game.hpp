#pragma once
#include <pspctrl.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Ball.hpp"

class Game
{
    public:
        Game();
        void Update(SceCtrlData& pad);
        void Draw();

    private:
        Player player;
        Enemy enemy;
        Ball ball;
};