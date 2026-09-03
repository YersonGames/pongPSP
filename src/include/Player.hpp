#pragma once
#include <pspctrl.h>

#include <raylib.h>

class Player
{
    public:
        Vector2 position;
        Vector2 size;
        float spd;

        Player(Vector2 getPos, Vector2 getSize);
        void Update(SceCtrlData& pad);
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