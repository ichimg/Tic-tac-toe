#include "ConsoleView.h"
#include <iostream>
ConsoleView::ConsoleView()
{
	m_firstPlayer = new LocalConsolePlayer("Player1", SymbolType::X);
	m_secondPlayer = new LocalConsolePlayer("Player2", SymbolType::O);
	m_gameMode = IPlayGame::Produce(EGameType::type1, m_firstPlayer, m_secondPlayer); 
}

void ConsoleView::Execute()
{
	do
	{
		Position firstPlayerChosenPosition = m_firstPlayer->RequestPutSymbol();
		while (!m_gameMode->IsEmptyPosition(firstPlayerChosenPosition, m_board))
		{
			std::cout << "The selected position is not valid, please enter another one." << std::endl;
			firstPlayerChosenPosition = m_firstPlayer->RequestPutSymbol();
		}
		m_firstPlayer->PutSymbol(m_board, firstPlayerChosenPosition);
		
		Position secondPlayerChosenPosition = m_secondPlayer->RequestPutSymbol();
		while (!m_gameMode->IsEmptyPosition(secondPlayerChosenPosition, m_board))
		{
			std::cout << "The selected position is not empty, please enter another one." << std::endl;
			secondPlayerChosenPosition = m_secondPlayer->RequestPutSymbol();
		}
		m_secondPlayer->PutSymbol(m_board, secondPlayerChosenPosition);

	} while (m_gameMode->IsWin(m_board) || m_gameMode->IsGameOver(m_board)); // isWin is not implemented => throwing exception
}
