#pragma once
#include "Board.h"
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
	static IPlayGamePtr Produce(EGameType type, IPlayer* firstPlayer, IPlayer* secondPlayer);
	bool virtual IsEmptyPosition(const Position& position, const Board& board) const = 0;
	bool virtual IsWin(const Board& board) const = 0;
	bool virtual IsGameOver(const Board& board) const = 0;
	virtual ~IPlayGame() = default;

private:
	Board m_board;
	IPlayer* m_firstPlayer;
	IPlayer* m_secondPlayer;
};

