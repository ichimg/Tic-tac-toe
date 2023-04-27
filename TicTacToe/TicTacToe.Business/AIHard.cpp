#include "AIHard.h"
#include "IPlayGame.h"

Position AIHard::GenerateMove(Board board)
{
    SymbolType m_symbol = SymbolType::O;
    // Check for winning moves
    for (int i = 1; i <= 9; i++) {
        if (board.at(i - 1) == SymbolType::Empty) {
            Board copy = board;
            copy.EmplaceSymbol(i - 1, m_symbol);
            if (copy.IsWin()) {
                return { (i - 1) / 3, (i - 1) % 3 };
            }
        }
    }
    // Check for blocking moves
    SymbolType opponentSymbol = m_symbol == SymbolType::X ? SymbolType::O : SymbolType::X;
    for (int i = 1; i <= 9; i++) {
        if (board.at(i - 1) == SymbolType::Empty) {
            Board copy = board;
            copy.EmplaceSymbol(i - 1, opponentSymbol);
            if (copy.IsWin()) {
                return { (i - 1) / 3, (i - 1) % 3 };
            }
        }
    }
    // Choose a random empty position
    for (int i = 1; i <= 9; i++) {
        if (board.at(i - 1) == SymbolType::Empty) {
            return { (i - 1) / 3, (i - 1) % 3 };
        }
    }
    throw std::runtime_error("No empty positions on the board.");
}

EStrategyType AIHard::GetStrategyType()
{
	return EStrategyType::AIHard;
}
