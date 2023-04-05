#pragma once
#include "IPlayGame.h"
#include "IGameListener.h"
#include "IStrategy.h"
#include "AIEasy.h"
#include "AIHard.h"
#include <vector>

class PlayGame : public IPlayGame
{
public:
	PlayGame(SymbolType symbol);
	void SetStrategy(EStrategyType type) override;
	EStrategyType GetStrategyType() const override;
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
	IStrategyPtr m_strategy;
};

