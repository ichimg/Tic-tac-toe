#pragma once
#include <string>
#include "IPlayer.h"
#include "ui_QtFrameworkUI.h"
#include <QtWidgets>

class LocalQtPlayer : public IPlayer, public QWidget
{
public:
	LocalQtPlayer(SymbolType symbol);
	
	virtual void PutSymbol(Board& board, const Position& position) override;
	virtual Position RequestPutSymbol() override;
	virtual std::string GetName() const override;
	virtual SymbolType GetSymbol() const override;
	virtual void ChangeSymbol();

	virtual void SetSymbol(const SymbolType& symbol) override;
	virtual void SetPosition(const Position& position) override;

private:
	SymbolType m_symbol;
	Position m_position;
};

