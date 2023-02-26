#include <QtCore/QCoreApplication>
#include "Board.h"
#include "iostream"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	Board board(3, 3);

	board.loadBoard();

	board.show();

	/**
	* Helper Functions
	*
	* getCurrentX() - get current element's line (int)
	*
	* getCurrentY() - get current element's row (int)
	*
	* getCurrentSymbol() - get current element's symbol (string)
	*
	* gameOverMessage() - displays winner at end of game
	*/

	return a.exec();
}
