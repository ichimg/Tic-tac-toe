#pragma once

enum class SymbolType : char
{
	X,
	O,
	Empty
};


/// <summary>
///     Converts SymbolType value that X or O to string.
/// </summary>
/// <param name="symbol">SymbolType value.</param>
/// <returns></returns>
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