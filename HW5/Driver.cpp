/*
Driver code for Assignment 5: Hash Tables
Created by: Anand
*/

#include <iostream>
#include <string>

#include "Element.h"
#include "HashTableS.h"
#include "HashTableQ.h"

using namespace std;

int main()
{
	cout << "\n\n ********** Testing the separate chaining-based hash table ********** \n\n";

	cout << "\n\n ----------  Testing constructor HashTableS(int size) ---------- \n";
	HashTableS myHashTableS(11);
	cout << "\n Programm output after constructor being called : ";
	myHashTableS.PrintTableEntry();
	cout << "\n Expected output after constructor being called : EMPTY \n\n";

	cout << "\n\n ----------  Testing void Insert(string x, double y, double z) ---------- \n";
	myHashTableS.Insert("00501", 40.81, -73.04);
	myHashTableS.Insert("00544", 40.81, -73.04);
	myHashTableS.Insert("00601", 18.16, -66.72);
	myHashTableS.Insert("00602", 18.38, -67.18);
	myHashTableS.Insert("00603", 18.43, -67.15);
	myHashTableS.Insert("00604", 18.43, -67.15);
	myHashTableS.Insert("00605", 18.43, -67.15);
	myHashTableS.Insert("00606", 18.18, -66.98);
	myHashTableS.Insert("00610", 18.28, -67.14);
	myHashTableS.Insert("00611", 18.28, -66.79);
	cout << "\n\n Programm output after Insert : \n\n";
	myHashTableS.PrintTableEntry();
	cout << "\n\n Expected output after Insert : \n\n 0: 00544, 40.81, -73.04 \n 4: 00501, 40.81, -73.04 \n 5: 00610, 18.28, -67.14 \n 5: 00601, 18.16, -66.72 \n 6: 00611, 18.28, -66.79 \n 6: 00602, 18.38, -67.18 \n 7: 00603, 18.43, -67.15 \n 8: 00604, 18.43, -67.15 \n 9: 00605, 18.43, -67.15 \n 10: 00606, 18.18, -66.98 \n\n";

	cout << "\n\n ----------  Testing void Remove(string x) --------- \n";
	myHashTableS.Remove("00501");
	myHashTableS.Remove("84321");
	myHashTableS.Insert("11724", 40.86, -73.44);						// Insert into Active/Empty slot
	myHashTableS.Insert("11726", 40.67, -73.39);						// Insert into Deleted slot
	cout << "\n\n Programm output after Remove and new Insert : \n\n";
	myHashTableS.PrintTableEntry();
	cout << "\n\n Expected output after Remove and new Insert : \n\n 0: 00544 , 40.810000 , -73.040000 \n 2: 11724, 40.860000, -73.440000 \n 4: 11726, 40.670000, -73.390000 \n 5: 00610, 18.280000, -67.140000 \n 5: 00601, 18.160000, -66.720000 \n 6: 00611, 18.280000, -66.790000 \n 6: 00602, 18.380000, -67.180000 \n 7: 00603, 18.430000, -67.150000 \n 8: 00604, 18.430000, -67.150000 \n 9: 00605, 18.430000, -67.150000 \n 10: 00606, 18.180000, -66.980000 \n\n";

	cout << "\n\n ----------  Testing bool Search(string x) ---------- \n\n";
	cout << "\n\n Programm output for Search zipcode 00601 : " << myHashTableS.Search("00601");
	cout << "\n\n Expected output for Search zipcode 00601 : 1 or TRUE";
	cout << "\n\n Programm output for Search zipcode 84321 : " << myHashTableS.Search("84321");
	cout << "\n\n Expected output for Search zipcode 84321 : 0 or FALSE \n\n";

	cout << "\n\n ---------  Testing double ComputeDistance((string x1, string x2) ---------- \n\n";
	cout << "\n\n Programm output for ComputeDistance between zipcodes 00601 & 00611 : " << myHashTableS.ComputeDistance("00601", "00611");
	cout << "\n\n Expected output for ComputeDistance between zipcodes 00601 & 00611 : 9.484 miles or 15.26 km \n\n";

	cout << "\n\n ---------- Testing int CountTableEntry(int i) --------- \n\n";
	cout << "\n\n Programm output for CountTableEntry for slot 1 : " << myHashTableS.CountTableEntry(1);
	cout << "\n\n Expected output for CountTableEntry for slot 1 : 0";
	cout << "\n\n Programm output for CountTableEntry for slot 9 : " << myHashTableS.CountTableEntry(9);
	cout << "\n\n Expected output for CountTableEntry for slot 9 : 1";


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n ********** Testing the quadratic probing-based hash table ********** \n\n";

	cout << "\n\n ----------  Testing constructor HashTableQ(int size) ---------- \n";
	HashTableQ myHashTableQ(11);
	cout << "\n Programm output after constructor being called : ";
	myHashTableQ.PrintTableEntry();
	cout << "\n Expected output after constructor being called : EMPTY \n\n";

	cout << "\n\n ----------  Testing void Insert(string x, double y, double z) ---------- \n";
	myHashTableQ.Insert("00501", 40.81, -73.04);
	myHashTableQ.Insert("00544", 40.81, -73.04);
	myHashTableQ.Insert("00601", 18.16, -66.72);
	myHashTableQ.Insert("00602", 18.38, -67.18);
	myHashTableQ.Insert("00603", 18.43, -67.15);
	myHashTableQ.Insert("00604", 18.43, -67.15);
	myHashTableQ.Insert("00605", 18.43, -67.15);
	myHashTableQ.Insert("00606", 18.18, -66.98);
	myHashTableQ.Insert("00610", 18.28, -67.14);
	myHashTableQ.Insert("00611", 18.28, -66.79);
	cout << "\n\n Programm output after Insert : \n\n";
	myHashTableQ.PrintTableEntry();
	cout << "\n\n Expected output after Insert : \n\n 0: 00544, 40.81, -73.04 \n 3: 00610, 18.28, -67.14 \n 4: 00501, 40.81, -73.04 \n 5: 00601, 18.16, -66.72 \n 6: 00602, 18.38, -67.18 \n 7: 00603, 18.43, -67.15 \n 8: 00604, 18.43, -67.15 \n 9: 00605, 18.43, -67.15 \n 10: 00606, 18.18, -66.98 \n\n";

	cout << "\n\n ----------  Testing void Remove(string x) --------- \n";
	myHashTableQ.Remove("00501");
	myHashTableQ.Remove("84321");
	myHashTableQ.Insert("11724", 40.86, -73.44);						// Insert into Active slot
	myHashTableQ.Insert("11726", 40.67, -73.39);						// Insert into Deleted slot
	cout << "\n\n Programm output after Remove and new Insert : \n\n";
	myHashTableQ.PrintTableEntry();
	cout << "\n\n Expected output after Remove and new Insert : \n\n 0: 00544, 40.81, -73.04 \n 2: 11724, 40.86, -73.44 \n 3: 00610, 18.28, -67.14 \n 4: 11726, 40.67, -73.39 \n 5: 00601, 18.16, -66.72 \n 6: 00602, 18.38, -67.18 \n 7: 00603, 18.43, -67.15 \n 8: 00604, 18.43, -67.15 \n 9: 00605, 18.43, -67.15 \n 10: 00606, 18.18, -66.98 \n\n";

	cout << "\n\n ----------  Testing bool Search(string x) ---------- \n\n";
	cout << "\n\n Programm output for Search zipcode 00601 : " << myHashTableQ.Search("00601");
	cout << "\n\n Expected output for Search zipcode 00601 : 1 or TRUE";
	cout << "\n\n Programm output for Search zipcode 84321 : " << myHashTableQ.Search("84321");
	cout << "\n\n Expected output for Search zipcode 84321 : 0 or FALSE \n\n";

	cout << "\n\n ---------  Testing double ComputeDistance((string x1, string x2) ---------- \n\n";
	cout << "\n\n Programm output for ComputeDistance between zipcodes 00601 & 00611 : " << myHashTableQ.ComputeDistance("00601", "00611");
	cout << "\n\n Expected output for ComputeDistance between zipcodes 00601 & 00611 : 9.484 miles or 15.26 km \n\n";


	cout << "\n\n\n\n";
	system("pause");
	return 0;
}