#include "QtFrameworkUI.h"
#include <QMessageBox>
#include "iostream"

QtFrameworkUI::QtFrameworkUI(QMainWindow* mainWindow, QWidget *parent)
    : QWidget(parent)
{
    m_gameMode = IPlayGame::Produce(EGameType::type1, SymbolType::X);
	m_gameMode->AddListener(this);

	DisplayMenu(mainWindow);
}

void QtFrameworkUI::DisplayWin(IPlayer* player)
{
	QMessageBox qm;
	qm.setText("Congratulations! Player " + QString(SymbolToChar(player->GetSymbol()))
		+ " has won!");
	qm.exec();
	close();
}

void QtFrameworkUI::DisplayMessage(const std::string& message) 
{
	QMessageBox qm;
	qm.setText(QString::fromStdString(message));
	qm.exec();
	close();
}

void QtFrameworkUI::DisplayMenu(QMainWindow *mainWindow)
{
	QMenuBar* menuBar = new QMenuBar(mainWindow);
	QMenu* fileMenu = menuBar->addMenu("Strategy");

	QAction* easyAI = new QAction("Easy AI", mainWindow);
	connect(easyAI, &QAction::triggered, this, &QtFrameworkUI::SetEasyAI);
	fileMenu->addAction(easyAI);

	QAction* hardAI = new QAction("Hard AI", mainWindow);
	connect(hardAI, &QAction::triggered, this, &QtFrameworkUI::SetHardAI);
	fileMenu->addAction(hardAI);

	mainWindow->setMenuBar(menuBar);
}

void QtFrameworkUI::SetEasyAI() {
	m_gameMode->SetStrategy(EStrategyType::AIEasy);
}

void QtFrameworkUI::SetHardAI() {
	m_gameMode->SetStrategy(EStrategyType::AIHard);
}

void QtFrameworkUI::InitBoard()
{
	gridLayout = new QGridLayout(this);

	for (int row = 0; row < 3; ++row) {
		for (int column = 0; column < 3; ++column) {
			QPushButton* button = new QPushButton(this);
			button->setFixedSize(100, 100);
			button->setFont(QFont("Arial", 32));
			gridLayout->addWidget(button, row, column);
			connect(button, &QPushButton::clicked, this, &QtFrameworkUI::Execute);
		}
	}
}

void QtFrameworkUI::RefreshBoard(){
	for (int row = 0; row < 3; ++row) {
		for (int column = 0; column < 3; ++column) {
			QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, column)->widget());
			if (button) {
				(m_gameMode->GetBoard().at(row * 3 + column) == SymbolType::X) ?
					button->setStyleSheet("color: #FF0000;") :
					button->setStyleSheet("color: #0000FF;");
				std::string symbol = SymbolToString(m_gameMode->GetBoard().at(row * 3 + column));
				button->setText(QString::fromStdString(symbol));
			}
		}
	}
}

Position QtFrameworkUI::SelectPosition()
{
	Position position;
	try
	{
		QPushButton* button = qobject_cast<QPushButton*>(sender());
		button->setText(QString(SymbolToChar(m_gameMode->GetPlayer()->GetSymbol())));
		(m_gameMode->GetPlayer()->GetSymbol() == SymbolType::X) ?
			button->setStyleSheet("color: #FF0000;") :
			button->setStyleSheet("color: #0000FF;");
		button->setEnabled(false);

		position = std::make_pair(gridLayout->indexOf(button) / 3, gridLayout->indexOf(button) % 3);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return position;
}

void QtFrameworkUI::Execute() 
{
	if (!m_gameMode->IsGameOver());
	{
		try
		{
			if (m_gameMode->GetRound() == ERound::PlayerRound)
			{
				Position chosenPosition = SelectPosition();
				m_gameMode->PutSymbol(chosenPosition);
			}
			else
			{
				m_gameMode->PutSymbol(std::make_pair<int, int>(-1, -1));
			}
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	
}

QtFrameworkUI::~QtFrameworkUI()
{}

void QtFrameworkUI::OnWin()
{
	RefreshBoard();
	DisplayWin(m_gameMode->GetPlayer());
	exit(0);
}

void QtFrameworkUI::OnDraw()
{
	RefreshBoard();
	DisplayMessage("Wow! It's a draw.");
	exit(0);
}

void QtFrameworkUI::OnMove()
{
	RefreshBoard();
}

std::string QtFrameworkUI::SymbolToString(const SymbolType& symbol)
{
	switch (symbol)
	{
	case SymbolType::X:
		return "X";
		break;
	case SymbolType::O:
		return "O";
		break;
	case SymbolType::Empty:
		return "";
		break;
	default:
		break;
	}
}