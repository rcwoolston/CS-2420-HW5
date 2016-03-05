#include <string>
#include "HashTableS.h"
#include "HashTableQ.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream fin, finZip;
	fstream finCompare;
	string tempString, tempZip, delimiter = ",",stringNumbers, stringX, stringY;
	HashTableS testTable(46255);
	HashTableQ testTableQ(42522 * 1.2);
	
	fin.open("zipcodes.csv");

	while (!fin.eof()) {
		fin >> tempString;

		// Get the zipcode
		tempZip = tempString.substr(0, tempString.find(delimiter));
		tempString.erase(0, tempString.find(delimiter) + delimiter.length());

		//Get the X coordinate
		stringX = tempString.substr(0, tempString.find(delimiter));
		tempString.erase(0, tempString.find(delimiter) + delimiter.length());

		//Get the Y coordinate
		stringY = tempString;

		testTable.Insert(tempZip,stod(stringX),stod(stringY));
		testTableQ.Insert(tempZip, stod(stringX), stod(stringY));
	}

	fin.close();

	//cout<<testTable.CountTableEntry(544);
	//testTable.PrintTableEntry(544);
	//cout<<testTable.CountTableEntry(601);
	//testTable.PrintTableEntry(601);

	//cout << testTable.Search("46856");

	//testTable.Remove("00601");
	//testTable.PrintTableEntry(601);

	//testTable.Search("00432");

	finZip.open("searchzip.txt");
	finCompare.open("validzip.txt", ios::in | ios::out | ios::trunc);

	while (!finZip.eof()) {
		finZip >> tempString;
		if (testTable.Search(tempString)) {
			finCompare << tempString << endl;
		}
	}

	finZip.close();

	finCompare.seekg(0);

	if (!finCompare.eof()) {
		finCompare >> tempZip;
	}

	while (!finCompare.eof()) {
		finCompare >> tempString;
		cout<<endl<<"Distance between: " <<tempZip<<" and "<<tempString<<" is:  "<<testTable.ComputeDistance(tempZip, tempString);
		tempZip = tempString;
	}

	finCompare.close();

	system("pause");
	
	return 0;
}