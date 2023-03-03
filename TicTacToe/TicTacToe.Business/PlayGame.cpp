#include "PlayGame.h"

IPlayGamePtr IPlayGame::Produce(EGameType type, IPlayer* firstPlayer, IPlayer* secondPlayer)
{
    if (type == EGameType::type1)
        return std::make_shared<PlayGame>(firstPlayer, secondPlayer);
    
    throw std::exception("Unknow game type.");
}

PlayGame::PlayGame(IPlayer* firstPlayer, IPlayer* secondPlayer)
{
    m_firstPlayer = firstPlayer;
    m_secondPlayer = secondPlayer;
}

bool PlayGame::IsEmptyPosition(const Position& position, const Board& board) const
{
    int positionInArray = position.first * Board::NO_OF_COLS + position.second;

    if (positionInArray > Board::SIZE - 1)
        return false;

    if (board.at(positionInArray) == SymbolType::Empty)
        return true;
    return false;
}

bool PlayGame::IsWin(const Board& board) const
{
    throw std::exception("Not implemented exception");
}

bool PlayGame::IsGameOver(const Board& board) const
{
    if (board.IsFull())
        return true;
    return false;
}
