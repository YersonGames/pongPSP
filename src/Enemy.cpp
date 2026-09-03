#include "include/Enemy.hpp"

#include "include/Ball.hpp"

Enemy::Enemy(Vector2 getPos, Vector2 getSize)
{
    position = getPos;
    size = getSize;
    spd = 5;
}

void Enemy::Update(Ball& ball)
{
    if (ball.GetHmove() == 1)
    {
        if (ball.GetY() < position.y+size.y/3) {position.y -= (spd*30)*GetFrameTime();}
        else if (ball.GetY() > position.y+size.y/1.5) {position.y += (spd*30)*GetFrameTime();}

        if (position.y < 0) {position.y = 0;}
        else if (position.y+size.y > 272) {position.y = 272-size.y;}
    }
}

void Enemy::Draw()
{
    DrawRectangle(position.x,position.y,size.x,size.y,WHITE);
}

//Getters
float Enemy::GetX() {return position.x;}
float Enemy::GetY() {return position.y;}
float Enemy::GetW() {return size.x;}
float Enemy::GetH() {return size.y;}