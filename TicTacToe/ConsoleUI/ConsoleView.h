#pragma once
#include <LocalConsolePlayer.h>
#include <Board.h>
#include <IPlayGame.h>
class ConsoleView
{
public:
	ConsoleView();
	void Execute();
	void DisplayWin(IPlayer* player);
	void DisplayBoard(const Board& board);
	void PutSymbol();

private:
	IPlayer* m_player;
	IPlayGamePtr m_gameMode;

private:
	char SymbolToChar(const SymbolType& symbol);
};

