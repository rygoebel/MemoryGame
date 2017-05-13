#include "Game.h"

Game::Game()
{
    level = GameLevel::Medium;
}

void Game::setLevel(GameLevel newLevel)
{
    level = newLevel;
}

GameLevel Game::getLevel()
{
    return level;
}

void Game::createNewGame()
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0, GAME_WIDTH, GAME_HEIGHT);
    gameBoard = new Board(gameScene);
    gameBoard->show();
}

void Game::endGame()
{
    delete gameScene;
}
