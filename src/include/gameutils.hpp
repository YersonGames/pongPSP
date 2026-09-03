#pragma once

namespace gameutils
{
    bool getCollision(float getX, float getY, float getW, float getH, auto& obj)
    {
        if (getX+getW > obj.GetX() && getX < obj.GetX()+obj.GetW() && getY+getH > obj.GetY() && getY < obj.GetY()+obj.GetH())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
