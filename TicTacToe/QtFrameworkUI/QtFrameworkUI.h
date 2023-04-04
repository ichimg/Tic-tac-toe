#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtFrameworkUI.h"
#include <IPlayGame.h>
#include <IPlayer.h>
#include "LocalQtPlayer.h"

class QtFrameworkUI : public QWidget, public IGameListener
{
    Q_OBJECT

public:
    QtFrameworkUI(QWidget *parent = nullptr);
	void DisplayWin(IPlayer* player);
	void DisplayMessage(const std::string& message);
	void DisplayBoard();
    ~QtFrameworkUI();

	virtual void OnWin() override;
	virtual void OnDraw() override;
	virtual Position OnMove() override;

private slots:
	void Execute();

private:
    Ui::QtFrameworkUIClass ui;

private:
	IPlayer* m_player;
	IPlayGamePtr m_gameMode;

};

