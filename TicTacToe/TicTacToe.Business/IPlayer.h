#pragma once
#include <utility>
#include "SymbolType.h"
class IPlayer
{
public:
	using Position = std::pair<int, int>;
	virtual Position PutSymbol() = 0;
	virtual ~IPlayer() = default;

private:
	SymbolType symbol;
};

