#include <string>
#include "HashTableS.h"
#include "HashTableQ.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

int main() {
	fstream fin, finZip;
	fstream finCompare;
	string tempString, tempZip, delimiter = ",",stringNumbers, stringX, stringY;
	HashTableS testTable(46255);
	HashTableQ testTableQ(42522 * 1.2);
	string prevTempStringThirtyS, tempStringThirtyS, prevTempStringThirtyQ, tempStringThirtyQ, prevTempStringFortyS, tempStringFortyS, prevTempStringFortyQ, tempStringFortyQ, prevTempStringFiftyS, tempStringFiftyS, prevTempStringFiftyQ, tempStringFiftyQ, prevTempStringTwoS, tempStringTwoS;
	int tempInt, SThirtyDistanceCalc = 0, QThirtyDistanceCalc = 0, SFortyDistanceCalc = 0, QFortyDistanceCalc = 0, SFiftyDistanceCalc = 0, QFiftyDistanceCalc = 0, STwoDistanceCalc = 0;
	clock_t SThirtyTimer = 0, SFortyTimer = 0, SFiftyTimer = 0, QThirtyTimer = 0, QFortyTimer = 0, QFiftyTimer = 0, STwoTimer = 0, tempTime = 0;

	////Read in data here
	fstream finCount;
	finCount.open("zipcodes.csv");
	fin.open("zipcodes.csv");

	int count = 0;

	//Count the number of entries in the file
	while (!finCount.eof()) {
		finCount >> tempString;
		count++;
	}
	count--;
	const int READ_IN_SIZE = (count-40000);
	
	//Reset to 0
	finCount.close();

	//Initialize arrays sizes
	int thirty = count/.3;
	int forty = count/.4;
	int fifty = count/.5;
	int two = count/2;

	//Initialize the size of the hash tables
	HashTableS tableThirtyS(thirty), tableFortyS(forty), tableFiftyS(fifty), tableTwoS(two);
	HashTableQ tableThirtyQ(thirty), tableFortyQ(forty), tableFiftyQ(fifty);
	tableThirtyS.setLoadFactor(.3);
	tableFortyS.setLoadFactor(.4);
	tableFiftyS.setLoadFactor(.5);
	tableTwoS.setLoadFactor(2);
	tableThirtyQ.setLoadFactor(.3);
	tableFortyQ.setLoadFactor(.4);
	tableFiftyQ.setLoadFactor(.5);

	count = 0;
	bool done = false;

	while (!fin.eof() && !done) {
			fin >> tempString;

			// Get the zipcode
			tempZip = tempString.substr(0, tempString.find(delimiter));
			tempString.erase(0, tempString.find(delimiter) + delimiter.length());

			//Get the X coordinate
			stringX = tempString.substr(0, tempString.find(delimiter));
			tempString.erase(0, tempString.find(delimiter) + delimiter.length());

			//Get the Y coordinate
			stringY = tempString;
			
			if (READ_IN_SIZE >= count) {
				cout << endl << endl << count;
				tempTime = clock();
				tableThirtyS.Insert(tempZip, stod(stringX), stod(stringY));
				SThirtyTimer += clock() - tempTime;

				tempTime = clock();
				tableFortyS.Insert(tempZip, stod(stringX), stod(stringY));
				SFortyTimer += clock() - tempTime;

				tempTime = clock();
				tableFiftyS.Insert(tempZip, stod(stringX), stod(stringY));
				SFiftyTimer += clock() - tempTime;

				tempTime = clock();
				tableTwoS.Insert(tempZip, stod(stringX), stod(stringY));
				STwoTimer += clock() - tempTime;

				tempTime = clock();
				tableThirtyQ.Insert(tempZip, stod(stringX), stod(stringY));
				QThirtyTimer += clock() - tempTime;

				tempTime = clock();
				tableFortyQ.Insert(tempZip, stod(stringX), stod(stringY));
				QFortyTimer += clock() - tempTime;

				tempTime = clock();
				tableFiftyQ.Insert(tempZip, stod(stringX), stod(stringY));
				QFiftyTimer += clock() - tempTime;

				count++;
			}
			else {
				done = true;
			}
	}

	fstream SThirty, SForty, SFifty, STwo, QThirty, QForty, QFifty;

	finZip.open("searchzip.txt");
	SThirty.open("validzipSThirty.txt", ios::in | ios::out | ios::trunc);
	SForty.open("validzipSForty.txt", ios::in | ios::out | ios::trunc);
	SFifty.open("validzipSFifty.txt", ios::in | ios::out | ios::trunc);
	STwo.open("validzipSTwo.txt", ios::in | ios::out | ios::trunc);

	QThirty.open("validzipQThirty.txt", ios::in | ios::out | ios::trunc);
	QForty.open("validzipQForty.txt", ios::in | ios::out | ios::trunc);
	QFifty.open("validzipQFifty.txt", ios::in | ios::out | ios::trunc);

	//Read in and output validzip codes
	while (!finZip.eof()) {
		finZip >> tempString;
		tempTime = clock();
		if (tableThirtyS.Search(tempString)) {
			SThirty << tempString << endl;
		}
		SThirtyTimer += clock() - tempTime;

		tempTime = clock();
		if (tableFortyS.Search(tempString)) {
			SForty << tempString << endl;
		}
		SFortyTimer += clock() - tempTime;

		tempTime = clock();
		if (tableFiftyS.Search(tempString)) {
			SFifty << tempString << endl;
		}
		SFiftyTimer += clock() - tempTime;

		tempTime = clock();
		if (tableTwoS.Search(tempString)) {
			STwo << tempString << endl;
		}
		STwoTimer += clock() - tempTime;

		tempTime = clock();
		if (tableThirtyQ.Search(tempString)) {
			QThirty << tempString << endl;
		}
		QThirtyTimer += clock() - tempTime;

		tempTime = clock();
		if (tableFortyQ.Search(tempString)) {
			QForty << tempString << endl;
		}
		QFortyTimer += clock() - tempTime;

		tempTime = clock();
		if (tableFiftyQ.Search(tempString)) {
			QFifty << tempString << endl;
		}
		QFiftyTimer += clock() - tempTime;
	}

	//Reset Seeks to 0
	SThirty.seekg(0);
	SForty.seekg(0);
	SFifty.seekg(0);
	STwo.seekg(0);
	QThirty.seekg(0);
	QForty.seekg(0);
	QFifty.seekg(0);
	
	SThirty >> prevTempStringThirtyS;
	SForty >> prevTempStringFortyS;
	SFifty >> prevTempStringFiftyS;
	STwo >> prevTempStringTwoS;
	QThirty >> prevTempStringThirtyQ;
	QForty >> prevTempStringFortyQ;
	QFifty >> prevTempStringFiftyQ;

	//Read in valid zips and get the distance between them, as well as the time to compute the distance
	count = 0;
	while (!SThirty.eof()) {
		SThirty >> tempStringThirtyS;
		SForty >> tempStringFortyS;
		SFifty >> tempStringFiftyS;
		STwo >> tempStringTwoS;
		QThirty >> tempStringThirtyQ;
		QForty >> tempStringFortyQ;
		QFifty >> tempStringFiftyQ;

		if (READ_IN_SIZE >= count) {
			count++;
			tempTime = clock();
			SThirtyDistanceCalc += tableThirtyS.ComputeDistance(prevTempStringThirtyS, tempStringThirtyS);
			prevTempStringThirtyS = tempStringThirtyS;
			SThirtyTimer += clock() - tempTime;

			tempTime = clock();
			QThirtyDistanceCalc += tableThirtyQ.ComputeDistance(prevTempStringThirtyQ, tempStringThirtyQ);
			prevTempStringThirtyQ = tempStringThirtyQ;
			QThirtyTimer += clock() - tempTime;

			tempTime = clock();
			SFortyDistanceCalc += tableFortyS.ComputeDistance(prevTempStringFortyS, tempStringFortyS);
			prevTempStringFortyS = tempStringFortyS;
			SFortyTimer += clock() - tempTime;

			tempTime = clock();
			QFortyDistanceCalc += tableFortyQ.ComputeDistance(prevTempStringFortyQ, tempStringFortyQ);
			prevTempStringFortyQ = tempStringFortyQ;
			QFortyTimer += clock() - tempTime;

			tempTime = clock();
			SFiftyDistanceCalc += tableFiftyS.ComputeDistance(prevTempStringFiftyS, tempStringFiftyS);
			prevTempStringFiftyS = tempStringFiftyS;
			SFiftyTimer += clock() - tempTime;

			tempTime = clock();
			QFiftyDistanceCalc += tableFiftyQ.ComputeDistance(prevTempStringFiftyQ, tempStringFiftyQ);
			prevTempStringFiftyQ = tempStringFiftyQ;
			QFiftyTimer += clock() - tempTime;

			tempTime = clock();
			STwoDistanceCalc += tableTwoS.ComputeDistance(prevTempStringTwoS, tempStringTwoS);
			prevTempStringTwoS = tempStringTwoS;
			STwoTimer += clock() - tempTime;
		}
	}

	cout << endl << endl << endl;
	cout << "**************Seperate Chaining Section********************";
	cout << endl << "First Seperate Chaining Table";
	cout << endl <<"Load Factor: "<<tableThirtyS.getLoadFactor();
	cout << endl << "Average Linked List Length: " << tableThirtyS.ALinkedListLength();


	cout << (SThirtyDistanceCalc / count);

	cout << tableThirtyS.ALinkedListLength();



		system("pause");
	
	return 0;
}