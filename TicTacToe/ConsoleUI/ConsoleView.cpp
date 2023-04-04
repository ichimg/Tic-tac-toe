#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView()
{
	m_gameMode = IPlayGame::Produce(EGameType::type1, SymbolType::X);
	m_gameMode->AddListener(this);
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

	} while (!m_gameMode->IsGameOver());
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

void ConsoleView::OnWin()
{
	DisplayBoard(m_gameMode->GetBoard());
	DisplayWin(m_gameMode->GetPlayer());
	exit(0);
}

void ConsoleView::OnDraw()
{
	DisplayBoard(m_gameMode->GetBoard());
	std::cout << "WOW, it's a DRAW!" << std::endl;
	exit(0);
}

Position ConsoleView::OnMove()
{
	Position position;
	std::cout << "<<<<<< Player " << SymbolToChar(m_gameMode->GetPlayer()->GetSymbol()) << std::endl;
	std::cout << "Enter the row you want to place your symbol ";
	std::cin >> position.first;

	std::cout << "Enter the column you want to place your symbol ";
	std::cin >> position.second;
	std::cout << std::endl;

	return position;
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
