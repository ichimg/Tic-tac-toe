#pragma once
#include "IPlayGame.h"
class PlayGame : public IPlayGame
{
public:
	PlayGame(IPlayer* firstPlayer, IPlayer* secondPlayer);
	bool virtual IsEmptyPosition(const Position& position, const Board& board) const override;
	bool virtual IsWin(const Board& board) const override;
	bool virtual IsGameOver(const Board& board) const;

private:
	
	IPlayer* m_firstPlayer;
	IPlayer* m_secondPlayer;
};

