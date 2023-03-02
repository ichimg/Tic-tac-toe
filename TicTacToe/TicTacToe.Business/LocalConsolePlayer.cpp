#include "LocalConsolePlayer.h"
#include <iostream>
#include "Board.h"

using Position = std::pair<int, int>;
LocalConsolePlayer::LocalConsolePlayer(std::string name, SymbolType symbol)
{
	m_name = name;
	m_symbol = symbol;
}
Position LocalConsolePlayer::PutSymbol()
{
	Position position;
	std::cout << "<<<<<< " << m_name << std::endl;
	std::cout << "Enter the row you want to place your symbol ";
	std::cin >> position.first;

	std::cout << "Enter the column you want to place your symbol ";
	std::cin >> position.second;
	std::cout << std::endl;

	if (position.first > Board::SIZE - 1 || position.second > Board::SIZE - 1)
		throw std::exception("Board index out of bound");

	return position;
}
