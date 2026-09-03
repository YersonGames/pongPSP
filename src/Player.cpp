#include "include/Player.hpp"

Player::Player(Vector2 getPos, Vector2 getSize)
{
    position = getPos;
    size = getSize;
    spd = 5;
}

void Player::Update(SceCtrlData& pad)
{
    if (pad.Buttons & PSP_CTRL_UP)
    {
        position.y -= (spd*30)*GetFrameTime();
    }
    else if (pad.Buttons & PSP_CTRL_DOWN)
    {
        position.y += (spd*30)*GetFrameTime();
    }

    if (position.y < 0) {position.y = 0;}
    else if (position.y+size.y > 272) {position.y = 272-size.y;}
}

void Player::Draw()
{
    DrawRectangle(position.x,position.y,size.x,size.y,WHITE);
}

//Getters
float Player::GetX() {return position.x;}
float Player::GetY() {return position.y;}
float Player::GetW() {return size.x;}
float Player::GetH() {return size.y;}