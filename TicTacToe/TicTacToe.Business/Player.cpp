#include "Player.h"


Player::Player(SymbolType symbol) : m_symbol{symbol}
{}

std::string Player::GetName() const
{
    return "Player " + SymbolToChar(m_symbol);
}

SymbolType Player::GetSymbol() const
{
    return m_symbol;
}

void Player::ChangeSymbol()
{
    m_symbol == SymbolType::X ? m_symbol = SymbolType::O : m_symbol = SymbolType::X;
}

void Player::SetSymbol(const SymbolType& symbol)
{
    m_symbol = symbol;
}

void Player::SetPosition(const Position& position)
{
}

Position Player::GetPosition() const
{
    throw std::exception("Not implemented exception");
}
