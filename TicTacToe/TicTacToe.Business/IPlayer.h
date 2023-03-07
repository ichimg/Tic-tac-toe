#pragma once
#include <utility>
#include <string>
#include "Board.h"
#include "SymbolType.h"
class IPlayer
{
public:
	using Position = std::pair<int, int>;
	virtual Position RequestPutSymbol() = 0;
	virtual void PutSymbol(Board& board, const Position& position) = 0;
	virtual std::string GetName() const = 0;
	virtual SymbolType GetSymbol() const = 0;
	virtual void ChangeSymbol() = 0;
	virtual ~IPlayer() = default;

private:
	SymbolType symbol;
	std::string m_name;
};

