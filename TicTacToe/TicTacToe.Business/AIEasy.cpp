#include "AIEasy.h"

Position AIEasy::GenerateMove(Board board)
{
	srand(time(NULL));
	int randIndex;
	do
	{
		randIndex = rand() % 9;
	} while (board.at(randIndex) != SymbolType::Empty ||
		board.at(randIndex) == SymbolType::X ||
		board.at(randIndex) == SymbolType::O);

	return Position(randIndex / 3, randIndex % 3);
}

EStrategyType AIEasy::GetStrategyType()
{
	return EStrategyType::AIEasy;
}
