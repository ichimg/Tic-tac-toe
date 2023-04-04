#include <QtCore/QCoreApplication>
#include "iostream"
#include "QtFrameworkUI.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QtFrameworkUI qt;
	try
	{
		qt.DisplayBoard();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}
	qt.show();

	return a.exec();
}
