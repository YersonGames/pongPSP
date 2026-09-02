#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <raylib.h>
#include <SDL3_mixer/SDL_mixer.h>

#include "include/Game.hpp"

PSP_MODULE_INFO("pongPSP", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main()
{
    InitWindow(480,272,"PongPSP");
    SetTargetFPS(30);

    SceCtrlData pad;
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    Game game;

    while (true)
    {
        sceCtrlReadBufferPositive(&pad, 1);

        game.Update(pad);

        BeginDrawing();

            ClearBackground(BLACK);
            game.Draw();
        
        EndDrawing();
    }
}