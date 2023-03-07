#pragma once
#include "IPlayGame.h"

class PlayGame : public IPlayGame
{
public:
	PlayGame(IPlayer* player);
	bool virtual IsEmptyPosition(const Position& position) const override;
	bool virtual IsWin() const override;
	bool virtual IsGameOver() const;
	virtual void PutSymbol(SymbolType symbol);
	virtual Board GetBoard() const;

private:
	Board m_board;
	IPlayer* m_player;
};

