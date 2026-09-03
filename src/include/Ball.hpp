#pragma once
#include <raylib.h>
#include "gameutils.hpp"
#include <cmath>

class Player;
class Enemy;

class Ball
{
    public:
        Vector2 position;
        float radius;
        float xspd;
        float yspd;
        short int hmove;
        short int vmove;

        Ball(Vector2 getPos, float getRad);
        void Update(Player& player, Enemy& enemy);
        void Draw();

        //Getters
        float GetX();
        float GetY();
        float GetW();
        float GetH();
        short int GetHmove();
};