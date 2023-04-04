#pragma once
#include <string>
#include "IPlayer.h"
class LocalConsolePlayer : public IPlayer
{
public:
	LocalConsolePlayer(SymbolType symbol);
	virtual Position RequestPutSymbol() override;
	virtual void PutSymbol(Board& board, const Position& position) override;
	virtual std::string GetName() const override;
	virtual SymbolType GetSymbol() const override;
	virtual void ChangeSymbol();

	virtual void SetSymbol(const SymbolType& symbol) override;
	virtual void SetPosition(const Position& position) override;

private:
	SymbolType m_symbol;
};

