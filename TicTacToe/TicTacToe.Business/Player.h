#pragma once
#include "IPlayer.h"
using Position = std::pair<int, int>;
class Player : public IPlayer
{
public:
	Player(SymbolType symbol);
	virtual std::string GetName() const override;
	virtual SymbolType GetSymbol() const override;
	virtual void ChangeSymbol() override;
	virtual void SetSymbol(const SymbolType& symbol) override;
	virtual void SetPosition(const Position& position) override;
	virtual Position GetPosition() const override;

private:
	std::string m_name;
	SymbolType m_symbol;
};

