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
	/// <summary>
	///		Returns SymbolType at given index.
	/// </summary>
	/// <param name="index"></param>
	/// <returns>SymbolType at given index.</returns>
	SymbolType at(int index) const;

	/// <summary>
	///		Checks if Board is filled.
	/// </summary>
	/// <returns>True or False value.</returns>
	bool IsFull() const;

	/// <summary>
	///		Emplaces Symbol on Board at position(x, y).
	/// </summary>
	/// <param name="position">An int value which specifies the position of symbol.</param>
	/// <param name="symbol">A SymboLType that stores X or O.</param>
	void EmplaceSymbol(int position, SymbolType symbol);

	/// <summary>
	/// Displays Board in Console.
	/// </summary>
	void Display() const;

	bool IsWin() const;


private:
	std::array<SymbolType, SIZE> m_boardView; // i * SIZE + j
};

