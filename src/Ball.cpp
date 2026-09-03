#include "include/Ball.hpp"

#include "include/Player.hpp"
#include "include/Enemy.hpp"

Ball::Ball(Vector2 getPos, float getRad)
{
    position = getPos;
    radius = getRad;
    xspd = 4;
    yspd = 0;
    hmove = -1;
    vmove = GetRandomValue(-1,1);
}

void Ball::Update(Player& player, Enemy& enemy)
{
    float moveStep = ((xspd*30)*hmove)*GetFrameTime();
    float step = std::ceil( std::abs(moveStep)/4);
    for (int i = 0; i < step;i++)
    {
        position.x += moveStep/step;
        if (gameutils::getCollision(position.x,position.y,radius,radius,player) || gameutils::getCollision(position.x,position.y,radius,radius,enemy))
        {
            hmove *= -1;

            if (xspd < 20) {xspd+=1;}

            if (yspd < 10) {yspd +=0.2;}
            if (vmove == 0) {vmove = GetRandomValue(-1,1);}

            break;
        }
    }
    position.y += ((yspd*30)*vmove)*GetFrameTime();

    if (position.y <= 0) {vmove = 1;}
    else if (position.y >= 272) {vmove = -1;}
}

void Ball::Draw()
{
    DrawCircle(position.x,position.y,radius,WHITE);
}

//Getters
float Ball::GetX() {return position.x;}
float Ball::GetY() {return position.y;}
float Ball::GetW() {return radius;}
float Ball::GetH() {return radius;}
short int Ball::GetHmove() {return hmove;}