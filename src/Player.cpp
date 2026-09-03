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

//Setters
void Player::SetX(float getX) {position.x = getX;}
void Player::SetY(float getY) {position.y = getY;}
void Player::SetW(float getW) {size.x = getW;}
void Player::SetH(float getH) {size.x = getH;}