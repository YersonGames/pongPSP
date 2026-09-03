#pragma once
#include <pspctrl.h>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Ball.hpp"
#include "Menu.hpp"
#include "GameState.hpp"

class Game
{
    public:
        Game();
        void Update(SceCtrlData& pad, SceCtrlData& padOld, bool& gameExit);
        void Draw();
        void RestartGame();

    private:
        GameState gameState;

        //Menu
        Menu menu;
        //Game
        Player player;
        Enemy enemy;
        Ball ball;
};