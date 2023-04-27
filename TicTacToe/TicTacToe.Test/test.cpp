#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Board.h"
#include "IPlayGame.h"
#include "SymbolType.h"

class MockPlayer : public IPlayer
{
public: 
	MOCK_METHOD(std::string, GetName, (), (const override));
	MOCK_METHOD(SymbolType, GetSymbol, (), (const override));
	MOCK_METHOD(void, ChangeSymbol, (), (override));
	MOCK_METHOD(void, SetSymbol, (const SymbolType& symbol), (override));
};

class MockStrategy : public IStrategy
{
public:
	MOCK_METHOD(Position, GenerateMove, (Board board), (override));
	MOCK_METHOD(EStrategyType, GetStrategyType, (), (override));
};

TEST(BoardTest, HavingBoardEmpty_WhenIsFull_ThenReturnFalse) 
{
	Board board;
	EXPECT_EQ(board.IsFull(), false);
}

TEST(BoardTest, HavingBoard_WhenEmplaceSymbol_ThenRetrieveSymbol)
{
	Board board;
	board.EmplaceSymbol(5, SymbolType::X);
	EXPECT_EQ(SymbolType::X, board.at(5));
}

TEST(BoardTest, HavingBoard_WhenEmplaceSymbol_ThenOtherPositionsExceptEmplacedOneAreEmpty)
{
	Board board;
	board.EmplaceSymbol(5, SymbolType::X);
	for (int i = 0; i < 9; i++)
		if (i != 5)
			EXPECT_EQ(board.at(i), SymbolType::Empty);
}

TEST(BoardTest, HavingBoard_WhenCreated_ThenBoardIsEmpty)
{
	Board board;
	for (int i = 0; i < 9; i++)
		EXPECT_EQ(board.at(i), SymbolType::Empty);
}

TEST(PlayGameTest, HavingPlayGameOnGoing_WhenIsWin_ThenReturnsFalse)
{
	IPlayer* player = new MockPlayer();
	IPlayGamePtr playGame = IPlayGame::Produce(EGameType::type1, SymbolType::X);

	EXPECT_EQ(playGame->IsWin(), false);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}