#pragma once
#include <QtWidgets>
#include "ui_QtFrameworkUI.h"
#include <IPlayGame.h>
#include <IPlayer.h>

class QtFrameworkUI : public QWidget, public IGameListener
{
    Q_OBJECT

public:
    QtFrameworkUI(QMainWindow* mainWindow, QWidget *parent = nullptr);
	void DisplayWin(IPlayer* player);
	void DisplayMessage(const std::string& message);
	void DisplayMenu(QMainWindow* mainWindow);
	void InitBoard();
	void RefreshBoard();
	Position SelectPosition();
    ~QtFrameworkUI();

	virtual void OnWin() override;
	virtual void OnDraw() override;
	virtual void OnMove() override;

	std::string SymbolToString(const SymbolType& symbol);

private slots:
	void Execute();
	void SetEasyAI();
	void SetHardAI();

private:
	QGridLayout* gridLayout;

private:
	IPlayGamePtr m_gameMode;
};

