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
	static IPlayGamePtr Produce(EGameType type, Board board, IPlayer* firstPlayer, IPlayer* secondPlayer);
	bool virtual IsEmptyPosition(Position position) const = 0;
	bool virtual IsWin() const = 0;
	bool virtual IsGameOver() const = 0;
	virtual ~IPlayGame() = default;

private:
	Board m_board;
	IPlayer* m_firstPlayer;
	IPlayer* m_secondPlayer;
};

