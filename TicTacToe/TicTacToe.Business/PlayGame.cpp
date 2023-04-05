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

void PlayGame::SetStrategy(EStrategyType type)
{
	switch (type)
	{
	case EStrategyType::AIEasy:
		m_strategy = std::make_shared<AIEasy>();
		break;
	case EStrategyType::AIHard:
		m_strategy = std::make_shared<AIHard>();
		break;
	default:
		break;
	}
}

EStrategyType PlayGame::GetStrategyType() const
{
	return m_strategy->GetStrategyType();
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
	if (m_board.IsWin())
		return true;
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
	if (m_strategy != 0 && m_player->GetSymbol() == SymbolType::O) {
		switch (m_strategy->GetStrategyType())
		{
		case EStrategyType::AIEasy:
			playerChosenPosition = m_strategy->GenerateMove(m_board);
		case EStrategyType::AIHard:
			playerChosenPosition = m_strategy->GenerateMove(m_board);
		}
	}
	else {
		for (const auto& listener : m_listeners)
		{
			playerChosenPosition = listener->OnMove();
		}
		if (!IsEmptyPosition(playerChosenPosition))
			throw std::exception("The selected position is not valid, please enter another one.");
	}

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
