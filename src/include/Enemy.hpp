#pragma once
#include <raylib.h>

class Ball;

class Enemy
{
    public:
        Vector2 position;
        Vector2 size;
        float spd;

        Enemy(Vector2 getPos, Vector2 getSize);
        void Update(Ball& ball);
        void Draw();

        //Getters
        float GetX();
        float GetY();
        float GetW();
        float GetH();

        //Setters
        void SetX(float getX);
        void SetY(float getY);
        void SetW(float getW);
        void SetH(float getH);
};