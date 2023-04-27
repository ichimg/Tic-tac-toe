#pragma once
#include "IStrategy.h"

class AIEasy : public IStrategy
{
public:
	Position GenerateMove(Board board) override;

	EStrategyType GetStrategyType() override;
};
