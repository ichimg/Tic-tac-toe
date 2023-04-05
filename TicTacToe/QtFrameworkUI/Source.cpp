#include <QtCore/QCoreApplication>
#include "iostream"
#include "QtFrameworkUI.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QMainWindow mainWindow;
	QtFrameworkUI qt(&mainWindow);

	try
	{
		qt.InitBoard();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}

	mainWindow.setCentralWidget(&qt);
	mainWindow.show();
	return a.exec();
}
