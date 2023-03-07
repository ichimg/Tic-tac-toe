#pragma once

enum class SymbolType : char
{
	X,
	O,
	Empty
};

static char SymbolToChar(const SymbolType& symbol)
{
    switch (symbol)
    {
    case SymbolType::X:
        return 'X';
        break;
    case SymbolType::O:
        return 'O';
        break;
    case SymbolType::Empty:
        return '_';
        break;
    default:
        break;
    }
}