#pragma once
#include "IStrategy.h"

class AIHard : public IStrategy
{
public:
	Position GenerateMove(Board board) override;

	EStrategyType GetStrategyType() override;
};

