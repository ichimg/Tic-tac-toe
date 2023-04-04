#include "ConsoleView.h"
#include "LocalConsolePlayer.h"
#include <iostream>
int main() {

	ConsoleView cv;
	try
	{
		cv.Execute();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}
	return 0;
}