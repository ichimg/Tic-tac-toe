#pragma once
#include <LocalConsolePlayer.h>
#include <Board.h>
#include <IPlayGame.h>
class ConsoleView
{
public:
	ConsoleView();
	void Execute();

private:
	Board m_board;
	IPlayer* m_firstPlayer;
	IPlayer* m_secondPlayer;
	IPlayGamePtr m_gameMode;
};

