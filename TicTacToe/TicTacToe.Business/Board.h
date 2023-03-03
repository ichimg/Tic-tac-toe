#pragma once
#include "SymbolType.h"
#include <array>
class Board
{
public:

public:
	Board();

public:
	static const size_t NO_OF_COLS = 3;
	static const size_t NO_OF_ROWS = 3;
	static const size_t SIZE = NO_OF_COLS * NO_OF_ROWS;
	SymbolType at(int index) const;
	bool IsFull() const;
	void EmplaceSymbol(int position, SymbolType symbol);


private:
	std::array<SymbolType, SIZE> m_boardView; // i * SIZE + j
};

