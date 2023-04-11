#pragma once
#include <Board.h>
#include <IPlayGame.h>
#include "IStrategy.h"

class ConsoleView : public IGameListener
{
public:
	ConsoleView();
	void SetConsoleStrategy();
	void Execute();
	void DisplayWin(IPlayer* player);
	void DisplayBoard(const Board& board);
	Position AskForPosition();

	void OnWin() override;
	void OnDraw() override;
	void OnMove() override;

private:
	IPlayGamePtr m_gameMode;

private:
	char SymbolToChar(const SymbolType& symbol);
};

