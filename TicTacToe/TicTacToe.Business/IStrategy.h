#pragma once
#include <iostream>
#include "Board.h"

enum class EStrategyType
{
	AIEasy,
	AIHard
};

using Position = std::pair<int, int>;
class IStrategy
{
public:
	virtual Position GenerateMove(Board board) = 0;
	virtual EStrategyType GetStrategyType() = 0;

	~IStrategy() = default;
};