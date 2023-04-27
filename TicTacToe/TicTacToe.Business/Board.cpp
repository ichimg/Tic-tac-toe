#include "Board.h"
#include <iostream>

Board::Board()
{
    m_boardView.fill(SymbolType::Empty);
}

SymbolType Board::at(int index) const
{
    return m_boardView.at(index);
}

bool Board::IsFull() const
{
    for (const auto& pos : m_boardView)
        if (pos == SymbolType::Empty)
            return false;
    return true;
}

void Board::EmplaceSymbol(int position, SymbolType symbol)
{
    m_boardView[position] = symbol;
}

void Board::Display() const
{
    int count = 0;
    for (const auto& elem : m_boardView)
    {
        if (count < 3)
        {
            std::cout << SymbolToChar(elem) << ' ';
            count++;
        }
        else
        {
            std::cout << std::endl << SymbolToChar(elem) << ' ';
            count = 1;
        }
    }
    std::cout << std::endl;
}

bool Board::IsWin() const
{
	// Check rows for winning pattern
	for (int i = 0; i < Board::SIZE; i += Board::NO_OF_ROWS)
	{
		if (m_boardView.at(i) == SymbolType::Empty)
			continue;

		if (m_boardView.at(i) == m_boardView.at(i + 1) && m_boardView.at(i + 1) == m_boardView.at(i + 2))
			return true;
	}

	// Check columns for winning pattern
	for (int i = 0; i < Board::NO_OF_COLS; i++)
	{
		if (m_boardView.at(i) == SymbolType::Empty)
			continue;

		if (m_boardView.at(i) == m_boardView.at(i + Board::NO_OF_COLS) && m_boardView.at(i + Board::NO_OF_COLS) == m_boardView.at(i + 2 * Board::NO_OF_COLS))
		{
			return true;
		}
	}

	// Check diagonals for winning pattern
	int firstPrincipalDiagonal = 0;
	if (m_boardView.at(firstPrincipalDiagonal) != SymbolType::Empty)
		if (
			m_boardView.at(firstPrincipalDiagonal) == m_boardView.at(firstPrincipalDiagonal + Board::NO_OF_ROWS + 1) &&
			m_boardView.at(firstPrincipalDiagonal + Board::NO_OF_ROWS + 1) == m_boardView.at(firstPrincipalDiagonal + 2 * Board::NO_OF_ROWS + 2)
			)
		{
			return true;
		}

	int firstSecondaryDiagonal = 2;
	if (m_boardView.at(firstSecondaryDiagonal) != SymbolType::Empty)
		if (
			m_boardView.at(firstSecondaryDiagonal) == m_boardView.at(2 * firstSecondaryDiagonal) &&
			m_boardView.at(2 * firstSecondaryDiagonal) == m_boardView.at(2 * firstSecondaryDiagonal + 2)
			)
		{
			return true;
		}

	// If no winning pattern found
	return false;
}