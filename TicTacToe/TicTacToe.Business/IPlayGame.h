#pragma once
#include "IPlayer.h"
#include <memory>

enum class EGameType
{
	type1
};

using IPlayGamePtr = std::shared_ptr<class IPlayGame>;
using Position = std::pair<int, int>;
class IPlayGame
{
public:
	static IPlayGamePtr Produce(EGameType type, IPlayer* player);
	bool virtual IsEmptyPosition(const Position& position) const = 0;
	bool virtual IsWin() const = 0;
	bool virtual IsGameOver() const = 0;
	virtual Board GetBoard() const = 0;
	virtual void PutSymbol(SymbolType symbol) = 0;
	virtual ~IPlayGame() = default;
};

