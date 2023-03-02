#include "PlayGame.h"

IPlayGamePtr IPlayGame::Produce(EGameType type, Board board, IPlayer* firstPlayer, IPlayer* secondPlayer)
{
    if (type == EGameType::type1)
        return std::make_shared<PlayGame>(board, firstPlayer, secondPlayer);
    
    throw std::exception("Unknow game type.");
}

PlayGame::PlayGame(Board board, IPlayer* firstPlayer, IPlayer* secondPlayer)
{
    m_board = board;
    m_firstPlayer = firstPlayer;
    m_secondPlayer = secondPlayer;
}

bool PlayGame::IsEmptyPosition(Position position) const
{
    int positionInArray = position.first * Board::SIZE + position.second;
    if (m_board.at(positionInArray) == SymbolType::Empty)
        return true;
    return false;
}

bool PlayGame::IsWin() const
{
    throw std::exception("Not implemented exception");
}

bool PlayGame::IsGameOver() const
{
    if (m_board.IsFull())
        return true;
    return false;
}