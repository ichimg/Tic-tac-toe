#include "QtFrameworkUI.h"
#include <QMessageBox>
#include "iostream"

QtFrameworkUI::QtFrameworkUI(QWidget *parent)
    : QWidget(parent)
{
    m_player = new LocalQtPlayer(SymbolType::X);
    m_gameMode = IPlayGame::Produce(EGameType::type1, m_player);
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
		QPushButton* button = qobject_cast<QPushButton*>(sender());
		if (button) {
			button->setText(QString(SymbolToChar(m_player->GetSymbol())));
			(m_player->GetSymbol() == SymbolType::X) ? button->setStyleSheet("color: #FF0000;") : button->setStyleSheet("color: #0000FF;");
			button->setEnabled(false);

			m_player->SetSymbol(m_player->GetSymbol());
			QGridLayout* layout = qobject_cast<QGridLayout*>(button->parentWidget()->layout());
			if (layout) {
				Position position(layout->indexOf(button) / 3, layout->indexOf(button) % 3);
				m_player->SetPosition(position);
			}
		}

		m_gameMode->PutSymbol(m_player->GetSymbol());
	}

}

QtFrameworkUI::~QtFrameworkUI()
{}

void QtFrameworkUI::OnWin()
{
	DisplayWin(m_player);
	exit(0);
}

void QtFrameworkUI::OnDraw()
{
	DisplayMessage("Wow! It's a draw.");
	exit(0);
}
