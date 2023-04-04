#pragma once
#include "IPlayGame.h"
#include "IGameListener.h"
#include <vector>

class PlayGame : public IPlayGame
{
public:
	PlayGame(SymbolType symbol);
	bool virtual IsEmptyPosition(const Position& position) const override;
	bool virtual IsWin() const override;
	bool virtual IsGameOver() const;
	virtual void PutSymbol(SymbolType symbol);
	virtual Board GetBoard() const;
	virtual IPlayer* GetPlayer() override;

	virtual void AddListener(IGameListener* listener) override;
	virtual void RemoveListener(IGameListener* listener) override;

	~PlayGame();

private:
	Board m_board;
	IPlayer* m_player;
	std::vector<IGameListener*> m_listeners;
};

