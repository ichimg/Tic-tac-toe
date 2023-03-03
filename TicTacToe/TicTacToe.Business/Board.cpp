#include "Board.h"

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
