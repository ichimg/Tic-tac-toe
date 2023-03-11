#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView()
{
	m_player = new LocalConsolePlayer(SymbolType::X);
	m_gameMode = IPlayGame::Produce(EGameType::type1, m_player); 
}

void ConsoleView::Execute()
{
	do
	{
		DisplayBoard(m_gameMode->GetBoard());

		try 
		{
			m_gameMode->PutSymbol(SymbolType::X);
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}

		if (m_gameMode->IsWin())
		{
			DisplayBoard(m_gameMode->GetBoard());
			DisplayWin(m_player);
			return;
		}

	} while (!m_gameMode->IsGameOver());

	if (m_gameMode->IsGameOver() && !m_gameMode->IsWin())
	{
		DisplayBoard(m_gameMode->GetBoard());
		std::cout << "WOW, it's a DRAW!" << std::endl;
	}
}

void ConsoleView::DisplayWin(IPlayer* player)
{
	std::cout << "Congratulations! Player " << SymbolToChar(player->GetSymbol())<< " has won!"<< std::endl;
}

void ConsoleView::DisplayBoard(const Board& board)
{
	board.Display();
	std::cout << std::endl;
}

void ConsoleView::PutSymbol()
{
}

char ConsoleView::SymbolToChar(const SymbolType& symbol)
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
