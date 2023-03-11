#include "LocalQtPlayer.h"

using Position = std::pair<int, int>;
LocalQtPlayer::LocalQtPlayer(SymbolType symbol)
{
	m_symbol = symbol;
}

void LocalQtPlayer::PutSymbol(Board& board, const Position& position)
{
	int positionInArray = position.first * Board::NO_OF_COLS + position.second;
	board.EmplaceSymbol(positionInArray, m_symbol);
}

std::string LocalQtPlayer::GetName() const
{
	return "Player " + SymbolToChar(m_symbol);
}

SymbolType LocalQtPlayer::GetSymbol() const
{
	return m_symbol;
}

void LocalQtPlayer::SetSymbol(const SymbolType &symbol)
{
	m_symbol = symbol;
}

void LocalQtPlayer::SetPosition(const Position& position)
{
	m_position = position;
}

void LocalQtPlayer::ChangeSymbol()
{
	m_symbol == SymbolType::X ? m_symbol = SymbolType::O : m_symbol = SymbolType::X;
}

Position LocalQtPlayer:: RequestPutSymbol() {
	return m_position;
}