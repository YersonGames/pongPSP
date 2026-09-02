#include "include/Game.hpp"

Game::Game()

    : player({16,136-24},{8,48})
{}

void Game::Update(SceCtrlData& pad)
{
    player.Update(pad);
}

void Game::Draw()
{
    player.Draw();
}