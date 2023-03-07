#include "LocalConsolePlayer.h"
#include <iostream>
#include "Board.h"

using Position = std::pair<int, int>;
LocalConsolePlayer::LocalConsolePlayer(SymbolType symbol)
{
	m_symbol = symbol;
}
Position LocalConsolePlayer::RequestPutSymbol()
{
	Position position;
	std::cout << "<<<<<< Player " << SymbolToChar(m_symbol) << std::endl;
	std::cout << "Enter the row you want to place your symbol ";
	std::cin >> position.first;

	std::cout << "Enter the column you want to place your symbol ";
	std::cin >> position.second;
	std::cout << std::endl;

	return position;
}

void LocalConsolePlayer::PutSymbol(Board& board, const Position& position)
{
	int positionInArray = position.first * Board::NO_OF_COLS + position.second;
	board.EmplaceSymbol(positionInArray, m_symbol);
}

std::string LocalConsolePlayer::GetName() const
{
	return "Player " + SymbolToChar(m_symbol);
}

SymbolType LocalConsolePlayer::GetSymbol() const
{
	return m_symbol;
}

void LocalConsolePlayer::ChangeSymbol()
{
	m_symbol == SymbolType::X ? m_symbol = SymbolType::O : m_symbol = SymbolType::X;
}
