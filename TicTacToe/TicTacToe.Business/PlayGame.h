#pragma once
#include "IPlayGame.h"
class PlayGame : public IPlayGame
{
public:
	PlayGame(Board board, IPlayer* firstPlayer, IPlayer* secondPlayer);
	bool virtual IsEmptyPosition(Position position) const override;
	bool virtual IsWin() const override;
	bool virtual IsGameOver() const;

private:
	Board m_board;
	IPlayer* m_firstPlayer;
	IPlayer* m_secondPlayer;
};

