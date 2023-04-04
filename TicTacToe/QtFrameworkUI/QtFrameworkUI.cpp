#include "QtFrameworkUI.h"
#include <QMessageBox>
#include "iostream"

QtFrameworkUI::QtFrameworkUI(QWidget *parent)
    : QWidget(parent)
{
    m_gameMode = IPlayGame::Produce(EGameType::type1, SymbolType::X);
	m_gameMode->AddListener(this);
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

void QtFrameworkUI::DisplayBoard()
{
	QGridLayout* gridLayout = new QGridLayout(this);

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

void QtFrameworkUI::Execute() {
	if (!m_gameMode->IsGameOver());
	{
		try
		{
			m_gameMode->PutSymbol(SymbolType::X);
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
	DisplayWin(m_gameMode->GetPlayer());
	exit(0);
}

void QtFrameworkUI::OnDraw()
{
	DisplayMessage("Wow! It's a draw.");
	exit(0);
}

Position QtFrameworkUI::OnMove()
{
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	Position position;
	if (button) {
		button->setText(QString(SymbolToChar(m_gameMode->GetPlayer()->GetSymbol())));
		(m_gameMode->GetPlayer()->GetSymbol() == SymbolType::X) ? button->setStyleSheet("color: #FF0000;") : button->setStyleSheet("color: #0000FF;");
		button->setEnabled(false);

		m_gameMode->GetPlayer()->SetSymbol(m_gameMode->GetPlayer()->GetSymbol());
		QGridLayout* layout = qobject_cast<QGridLayout*>(button->parentWidget()->layout());
		if (layout) {
			position = std::make_pair(layout->indexOf(button) / 3, layout->indexOf(button) % 3);
		}
	}
	return position;
}
