#include "include/Game.hpp"

Game::Game()

    :   player({16,136-24},{8,48}),
        enemy({480-24,136-24},{8,48}),
        ball({480/2,272/2},4)
{}

void Game::Update(SceCtrlData& pad)
{
    player.Update(pad);
    enemy.Update(ball);
    ball.Update(player,enemy);
}

void Game::Draw()
{
    player.Draw();
    enemy.Draw();
    ball.Draw();

    DrawLine(0,0,480,0,WHITE);
    DrawLine(0,271,480,271,WHITE);
}