#pragma once
#include <QtWidgets>
#include <string>
#include <iostream>

class Board : public QWidget
{
public:
	Board(int lines, int rows, QWidget* parent = nullptr);

	void loadBoard();

	const int& getCurrentLine();

	const int& getCurrentRow();

	const std::string& getCurrentSymbol();

	void gameOverMessage();

private slots:
	void buttonClicked();

private:
	QString m_currentSymbol;
	int m_currentLine;
	int m_currentRow;
	int m_lines;
	int m_rows;
};

