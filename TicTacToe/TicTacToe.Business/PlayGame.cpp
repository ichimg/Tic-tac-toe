#include "PlayGame.h"
#include "Player.h"

IPlayGamePtr IPlayGame::Produce(EGameType type, SymbolType symbol)
{
    if (type == EGameType::type1)
        return std::make_shared<PlayGame>(SymbolType::X);
    
    throw std::exception("Unknow game type.");
}

PlayGame::PlayGame(SymbolType symbol)
{
    m_player = new Player(symbol);
}

bool PlayGame::IsEmptyPosition(const Position& position) const
{
    int positionInArray = position.first * Board::NO_OF_COLS + position.second;

    if (positionInArray > Board::SIZE - 1)
        return false;

    if (m_board.at(positionInArray) == SymbolType::Empty)
        return true;
    return false;
}

bool PlayGame::IsWin() const
{
    // Check rows for winning pattern
    for (int i = 0; i < Board::SIZE; i+=Board::NO_OF_ROWS) 
    {
        if (m_board.at(i) == SymbolType::Empty)
            continue;

        if (m_board.at(i) == m_board.at(i + 1) && m_board.at(i + 1) == m_board.at(i + 2))
            return true;
    }

    // Check columns for winning pattern
    for (int i = 0; i < Board::NO_OF_COLS; i++) 
    {
        if (m_board.at(i) == SymbolType::Empty)
            continue;

        if (m_board.at(i) == m_board.at(i + Board::NO_OF_COLS) && m_board.at(i + Board::NO_OF_COLS) == m_board.at(i + 2*Board::NO_OF_COLS))
        {
            return true;
        }
    }

    // Check diagonals for winning pattern
    int firstPrincipalDiagonal = 0;
    if(m_board.at(firstPrincipalDiagonal) != SymbolType::Empty)
        if (
            m_board.at(firstPrincipalDiagonal) == m_board.at(firstPrincipalDiagonal + Board::NO_OF_ROWS + 1) && 
            m_board.at(firstPrincipalDiagonal + Board::NO_OF_ROWS + 1) == m_board.at(firstPrincipalDiagonal + 2*Board::NO_OF_ROWS + 2)
           )
            {
                return true;
            }

    int firstSecondaryDiagonal = 2;
    if (m_board.at(firstSecondaryDiagonal) != SymbolType::Empty)
        if (
            m_board.at(firstSecondaryDiagonal) == m_board.at(2*firstSecondaryDiagonal) && 
            m_board.at(2 * firstSecondaryDiagonal) == m_board.at(2 * firstSecondaryDiagonal + 2)
           )
        {
            return true;
        }

    // If no winning pattern found
    return false;
}

bool PlayGame::IsGameOver() const
{
    if (m_board.IsFull())
        return true;
    return false;
}

void PlayGame::PutSymbol(SymbolType symbol)
{
    Position playerChosenPosition;
    for (const auto& listener : m_listeners)
    {
        playerChosenPosition = listener->OnMove();
    }

    if (!IsEmptyPosition(playerChosenPosition))
        throw std::exception("The selected position is not valid, please enter another one.");

    int positionInArray = playerChosenPosition.first * Board::NO_OF_COLS + playerChosenPosition.second;
    m_board.EmplaceSymbol(positionInArray, m_player->GetSymbol());

    if (!IsWin())
    {
        m_player->ChangeSymbol();
    }
    else
    {
        for (const auto& listener : m_listeners)
        {
               listener->OnWin();
        }
    }

    if (IsGameOver() && !IsWin())
    {
        for (const auto& listener : m_listeners)
        {
                listener->OnDraw();
        }
    }

}

Board PlayGame::GetBoard() const
{
    return m_board;
}

IPlayer* PlayGame::GetPlayer()
{
    return m_player;
}

void PlayGame::AddListener(IGameListener* listener)
{
    m_listeners.emplace_back(listener);
}

void PlayGame::RemoveListener(IGameListener* listener)
{
    for (auto it = m_listeners.begin(); it != m_listeners.end(); )
    {
            if (*it == listener)
                it = m_listeners.erase(it);
            else
                ++it;
    }
}

PlayGame::~PlayGame()
{

}
