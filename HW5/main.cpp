//#include <string>
//#include "HashTableS.h"
//#include "HashTableQ.h"
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//	fstream fin, finZip;
//	fstream finCompare;
//	string tempString, tempZip, delimiter = ",",stringNumbers, stringX, stringY;
//	HashTableS testTable(46255);
//	HashTableQ testTableQ(42522 * 1.2);
//	
//	//fin.open("zipcodes.csv");
//
//	//while (!fin.eof()) {
//	//	fin >> tempString;
//
//	//	// Get the zipcode
//	//	tempZip = tempString.substr(0, tempString.find(delimiter));
//	//	tempString.erase(0, tempString.find(delimiter) + delimiter.length());
//
//	//	//Get the X coordinate
//	//	stringX = tempString.substr(0, tempString.find(delimiter));
//	//	tempString.erase(0, tempString.find(delimiter) + delimiter.length());
//
//	//	//Get the Y coordinate
//	//	stringY = tempString;
//	//	
//	//	if (stoi(tempZip) > 0) {
//	//		testTable.Insert(tempZip, stod(stringX), stod(stringY));
//	//		testTableQ.Insert(tempZip, stod(stringX), stod(stringY));
//	//	}
//	//}
//
//	//fin.close();
//
//	//cout<<testTable.CountTableEntry(544);
//	//testTable.PrintTableEntry(544);
//	//testTableQ.PrintTableEntry(544);
//	//cout<<testTable.CountTableEntry(601);
//	//testTable.PrintTableEntry(601);
//	//testTableQ.PrintTableEntry(601);
//
//	//cout << testTable.Search("46856");
//	//cout << testTableQ.Search("46856");
//
//	//testTableQ.Remove("46856");
//
//	//cout<<testTableQ.Search("46856");
//
//	//testTable.Remove("00601");
//	//testTable.PrintTableEntry(601);
//
//	//testTable.Search("00432");
//
//	//finZip.open("searchzip.txt");
//	//finCompare.open("validzip.txt", ios::in | ios::out | ios::trunc);
//
//	//while (!finZip.eof()) {
//	//	finZip >> tempString;
//	//	if (testTable.Search(tempString)) {
//	//		finCompare << tempString << endl;
//	//	}
//	//	if (testTableQ.Search(tempString)) {
//	//		finCompare << tempString << endl;
//	//	}
//	//}
//
//	//finZip.close();
//
//	//finCompare.seekg(0);
//
//	//if (!finCompare.eof()) {
//	//	finCompare >> tempZip;
//	//}
//
//	//while (!finCompare.eof()) {
//	//	finCompare >> tempString;
//	//	cout<<endl<<"Distance between: " <<tempZip<<" and "<<tempString<<" is:  "<<testTable.ComputeDistance(tempZip, tempString);
//	//	tempZip = tempString;
//	//}
//
//	//finCompare.close();
//
//	//system("pause");
//
//
//	// Real program starts down here
//	////Add Driver code here
//
//	////Read in data here
//	fstream finCount;
//	finCount.open("zipcodes.csv");
//	fin.open("zipcodes.csv");
//
//	int count = 0;
//
//	//Count the number of entries in the file
//	while (!finCount.eof()) {
//		finCount >> tempString;
//		count++;
//	}
//	count--;
//	
//	//Reset to 0
//	finCount.close();
//
//	//Initialize arrays sizes
//	int thirty = count/.3;
//	int forty = count/.4;
//	int fifty = count/.5;
//	int two = count * 2;
//
//	//Initialize the size of the hash tables
//	HashTableS tableThirtyS(thirty), tableFortyS(forty), tableFiftyS(fifty), tableTwoS(two);
//	HashTableQ tableThirtyQ(thirty), tableFortyQ(forty), tableFiftyQ(fifty), tableTwoQ(two);
//	count = 0;
//	bool done = false;
//
//	while (!fin.eof() && !done) {
//			fin >> tempString;
//
//			// Get the zipcode
//			tempZip = tempString.substr(0, tempString.find(delimiter));
//			tempString.erase(0, tempString.find(delimiter) + delimiter.length());
//
//			//Get the X coordinate
//			stringX = tempString.substr(0, tempString.find(delimiter));
//			tempString.erase(0, tempString.find(delimiter) + delimiter.length());
//
//			//Get the Y coordinate
//			stringY = tempString;
//			
//			if (stoi(tempZip) > 0) {
//				tableThirtyS.Insert(tempZip, stod(stringX), stod(stringY));
//				tableFortyS.Insert(tempZip, stod(stringX), stod(stringY));
//				tableFiftyS.Insert(tempZip, stod(stringX), stod(stringY));
//				tableTwoS.Insert(tempZip, stod(stringX), stod(stringY));
//				tableThirtyQ.Insert(tempZip, stod(stringX), stod(stringY));
//				tableFortyQ.Insert(tempZip, stod(stringX), stod(stringY));
//				tableFiftyQ.Insert(tempZip, stod(stringX), stod(stringY));
//				tableTwoQ.Insert(tempZip, stod(stringX), stod(stringY));
//				count++;
//			}
//			else {
//				done = true;
//			}
//	}
//
//	fstream SThirty, SForty, SFifty, STwo, QThirty, QForty, QFifty, QTwo;
//
//	finZip.open("searchzip.txt");
//	SThirty.open("validzipSThirty.txt", ios::in | ios::out | ios::trunc);
//	SForty.open("validzipSForty.txt", ios::in | ios::out | ios::trunc);
//	SFifty.open("validzipSFifty.txt", ios::in | ios::out | ios::trunc);
//	STwo.open("validzipSTwo.txt", ios::in | ios::out | ios::trunc);
//
//	QThirty.open("validzipQThirty.txt", ios::in | ios::out | ios::trunc);
//	QForty.open("validzipQForty.txt", ios::in | ios::out | ios::trunc);
//	QFifty.open("validzipQFifty.txt", ios::in | ios::out | ios::trunc);
//	QTwo.open("validzipQTwo.txt", ios::in | ios::out | ios::trunc);
//
//	//Read in and output validzip codes
//	while (!finZip.eof()) {
//		finZip >> tempString;
//		if (tableThirtyS.Search(tempString)) {
//			SThirty << tempString << endl;
//		}
//		if (tableFortyS.Search(tempString)) {
//			SForty << tempString << endl;
//		}
//		if (tableFiftyS.Search(tempString)) {
//			SFifty << tempString << endl;
//		}
//		if (tableTwoS.Search(tempString)) {
//			STwo << tempString << endl;
//		}
//		if (tableThirtyQ.Search(tempString)) {
//			QThirty << tempString << endl;
//		}
//		if (tableFortyQ.Search(tempString)) {
//			QForty << tempString << endl;
//		}
//		if (tableFiftyQ.Search(tempString)) {
//			QFifty << tempString << endl;
//		}
//		if (tableTwoQ.Search(tempString)) {
//			QTwo << tempString << endl;
//		}
//	}
//
//	//Reset Seeks to 0
//	SThirty.seekg(0);
//	SForty.seekg(0);
//	SFifty.seekg(0);
//	STwo.seekg(0);
//	QThirty.seekg(0);
//	QForty.seekg(0);
//	QFifty.seekg(0);
//	QTwo.seekg(0);
//
//	string prevTempStringThirty, tempStringThirty;
//	int SThirtyDistanceCalc = 0, tempInt;
//
//	SThirty >> prevTempStringThirty;
//
//	//Read in valid zips and get the distance between them, as well as the time to compute the distance
//	count = 0;
//	while (!SThirty.eof()) {
//		SThirty >> tempStringThirty;
//
//		if (stoi(tempStringThirty) > 0) {
//			count++;
//			tempInt = tableThirtyS.ComputeDistance(prevTempStringThirty, tempStringThirty);
//			if (tempInt > 0) {
//				SThirtyDistanceCalc += tempInt;
//			}
//			prevTempStringThirty = tempStringThirty;
//		}
//	}
//
//	cout << (SThirtyDistanceCalc / count);
//
//	cout << tableThirtyS.ALinkedListLength();
//
//
//
//	system("pause");
//	
//	return 0;
//}