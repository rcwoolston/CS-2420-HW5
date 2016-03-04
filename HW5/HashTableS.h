#pragma once

#include <string>

using namespace std;

class HashTableS // separate chaining
{
private:
	int m; // the size of the table
	Element ** T; // the hash table
	int Hash(string x); // the hash function
public:
	HashTableS(int size);
	void Insert(string x, double y, double z); // insert a new element with key x and other info
	void Remove(string x); // remove an element whose key is x
	bool Search(string x); // search an element whose key is x and return true if found
	double ComputeDistance(string x1, string x2); // return the distance between two zip codes.
												  // assume both zip codes are valid ones.
	int CountTableEntry(int i); // return the number of elements in the ith slot of the hash table
	void PrintTableEntry(); // print the element in the hash table
};
