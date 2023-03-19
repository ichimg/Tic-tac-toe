#include "ConsoleListener.h"

ConsoleListener::ConsoleListener(IGamePtr game): m_game(game)
{}

void ConsoleListener::OnMakeMove()
{
	std::cout << "Event on move";
}

void ConsoleListener::OnGameOver()
{
	std::cout << "Event on game over";
}
