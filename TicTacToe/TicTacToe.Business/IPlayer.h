#pragma once
#include <utility>
#include "Board.h"
#include "SymbolType.h"
class IPlayer
{
public:
	using Position = std::pair<int, int>;
	virtual Position RequestPutSymbol() = 0;
	virtual void PutSymbol(Board& board, const Position& position) = 0;
	virtual ~IPlayer() = default;

private:
	SymbolType symbol;
};

