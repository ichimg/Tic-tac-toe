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


