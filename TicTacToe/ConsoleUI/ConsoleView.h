#pragma once
#include <LocalConsolePlayer.h>
#include <Board.h>
#include <IPlayGame.h>
#include <IGameListener.h>
class ConsoleView : public IGameListener
{
public:
	ConsoleView();
	void Execute();
	void DisplayWin(IPlayer* player);
	void DisplayBoard(const Board& board);
	void PutSymbol();

	void OnWin() override;
	void OnDraw() override;

private:
	IPlayer* m_player;
	IPlayGamePtr m_gameMode;

private:
	char SymbolToChar(const SymbolType& symbol);
};

