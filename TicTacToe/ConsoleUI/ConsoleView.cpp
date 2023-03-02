#include "ConsoleView.h"
#include <iostream>
ConsoleView::ConsoleView()
{
	m_firstPlayer = new LocalConsolePlayer("Player1", SymbolType::X);
	m_secondPlayer = new LocalConsolePlayer("Player2", SymbolType::O);
	m_gameMode = IPlayGame::Produce(EGameType::type1, m_board, m_firstPlayer, m_secondPlayer); 
}

void ConsoleView::Execute()
{
	do 
	{
		Position firstPlayerChosenPosition = m_firstPlayer->PutSymbol();
		Position secondPlayerChosenPosition = m_secondPlayer->PutSymbol();
		

	} while (m_gameMode->IsWin() || m_gameMode->IsGameOver());
}
