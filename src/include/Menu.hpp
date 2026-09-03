#pragma once
#include <raylib.h>
#include <pspctrl.h>
#include "GameState.hpp"

class Menu
{
    public:
        Menu();
        void Update(SceCtrlData& pad, SceCtrlData& padOld, GameState& gameState, bool& gameExit);
        void Draw();

    private:
        short int selectMenu1;
        Color colorSMenu1[2];
};