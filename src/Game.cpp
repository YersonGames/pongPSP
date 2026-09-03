#include "include/Game.hpp"

Game::Game()

    :   gameState(GameState::MENU1),
        player({0},{8,48}),
        enemy({0,0},{8,48}),
        ball({0,0},4)
{
    RestartGame();
}

void Game::Update(SceCtrlData& pad, SceCtrlData& padOld, bool& gameExit)
{
    switch (gameState)
    {
    case GameState::MENU1 :
        menu.Update(pad, padOld, gameState, gameExit);
        break;
    
    case GameState::GAME :
        player.Update(pad);
        enemy.Update(ball);
        ball.Update(player,enemy);

        if (pad.Buttons & PSP_CTRL_START)
        {
            gameState = GameState::MENU1;
            RestartGame();
        }
        break;
    }
}

void Game::Draw()
{
    switch (gameState)
    {
        case GameState::MENU1 :
            menu.Draw();
            break;
        case GameState::GAME :
            player.Draw();
            enemy.Draw();
            ball.Draw();

            DrawLine(0,0,480,0,WHITE);
            DrawLine(0,271,480,271,WHITE);
    }
    
}

void Game::RestartGame()
{
    player.SetX(16);
    player.SetY(136-24);
    enemy.SetX(480-24);
    enemy.SetY(136-24);
    ball.SetX(480/2);
    ball.SetY(272/2);
    ball.DefaultVal();
}