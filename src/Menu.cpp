#include "include/Menu.hpp"
#include "include/Game.hpp"

Menu::Menu()
{
    selectMenu1 = 1;
}

void Menu::Update(SceCtrlData& pad, SceCtrlData& padOld, GameState& gameState, bool& gameExit)
{
    if (selectMenu1 == 1)
    {
        colorSMenu1[0] = RED;
        colorSMenu1[1] = WHITE;
    }
    else if (selectMenu1 == 2)
    {
        colorSMenu1[0] = WHITE;
        colorSMenu1[1] = RED;
    }

    if ((pad.Buttons & PSP_CTRL_DOWN) && !(padOld.Buttons & PSP_CTRL_DOWN))
    {
        selectMenu1 += 1;
    }
    else if ((pad.Buttons & PSP_CTRL_UP) && !(padOld.Buttons & PSP_CTRL_UP))
    {
        selectMenu1 -= 1;
    }

    if (pad.Buttons & PSP_CTRL_CROSS)
    {
        if (selectMenu1 == 1)
        {
            gameState = GameState::GAME;
        }
        else if (selectMenu1 == 2)
        {
            gameExit = true;
        }
    }

    if (selectMenu1 > 2) {selectMenu1 = 1;}
    else if (selectMenu1 < 1) {selectMenu1 = 2;}

    padOld = pad;
}

void Menu::Draw()
{
    DrawText("Pong",(float)(480-MeasureText("Pong",24))/2,8,24,WHITE);

    DrawText("Play",(float)(480-MeasureText("Play",24))/2,128,16,colorSMenu1[0]);
    DrawText("Quit",(float)(480-MeasureText("Quit",24))/2,128+24,16,colorSMenu1[1]);
}