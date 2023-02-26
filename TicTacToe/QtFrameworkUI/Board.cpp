#include "Board.h"

Board::Board(int lines, int rows, QWidget* parent) : QWidget(parent) {
	m_currentSymbol = "X";
	m_currentLine = 0;
	m_currentRow = 0;
	m_lines = lines;
	m_rows = rows;
}

void Board::loadBoard()
{
	QGridLayout* gridLayout = new QGridLayout(this);

	for (int row = 0; row < m_lines; ++row) {
		for (int column = 0; column < m_rows; ++column) {
			QPushButton* button = new QPushButton(this);
			button->setFixedSize(100, 100);
			button->setFont(QFont("Arial", 32));
			gridLayout->addWidget(button, row, column);
			connect(button, &QPushButton::clicked, this, &Board::buttonClicked);
		}
	}
}

void Board::buttonClicked() {
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	if (button) {
		button->setText(m_currentSymbol);
		(m_currentSymbol == "X") ? button->setStyleSheet("color: #FF0000;") : button->setStyleSheet("color: #0000FF;");
		button->setEnabled(false);

		m_currentSymbol = (m_currentSymbol == "X") ? "O" : "X";
		QGridLayout* layout = qobject_cast<QGridLayout*>(button->parentWidget()->layout());
		if (layout) {
			m_currentLine = layout->indexOf(button) / m_rows;
			m_currentRow = layout->indexOf(button) % m_rows;
		}
	}
}

const int& Board::getCurrentLine()
{
	return m_currentLine;
}

const int& Board::getCurrentRow()
{
	return m_currentRow;
}

const std::string& Board::getCurrentSymbol()
{
	return m_currentSymbol.toStdString();
}

void Board::gameOverMessage()
{
	QMessageBox qm;
	if (m_currentSymbol == "X")
		qm.setText("Game Over | O is the winner");
	else
		qm.setText("Game Over | X is the winner");
	qm.exec();
	close();
}
