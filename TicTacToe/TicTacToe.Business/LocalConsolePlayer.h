#pragma once
#include <string>
#include "IPlayer.h"
class LocalConsolePlayer : public IPlayer
{
public:
	LocalConsolePlayer(std::string name, SymbolType symbol);
	virtual Position PutSymbol() override;

private:
	SymbolType m_symbol;
	std::string m_name;
};

