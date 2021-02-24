#include "Spreadsheet.h"
#include <iostream>

using namespace std;

class SpreadsheetApplication {};

int main()
{
	SpreadsheetApplication theApp;
	Spreadsheet s1(theApp);
	Spreadsheet s3(theApp, 5, 6);
	Spreadsheet s4 = s3;

	s1.setCellAt(1, 1, SpreadsheetCell(9));
	cout << s1.getCellAt(1, 1).getValue() << endl;

	s4 = s1;
	cout << s4.getCellAt(1, 1).getValue() << endl;

	return 0;
}
