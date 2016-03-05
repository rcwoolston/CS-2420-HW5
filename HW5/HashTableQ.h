#pragma once
#include <string>

using namespace std;

class ElementQ  // Define a linked list node 
{
public: int key;
		double x, y;
		string zipCode;
		int flag;		 // 0: empty; 1: active; 2: deleted
		ElementQ(int key_input = 0, string newZipCode = "", double newX = 0, double newY = 0, int newFlag=0) {
			key = key_input;
			zipCode = newZipCode;
			x = newX;
			y = newY;
			flag = newFlag;
		}
};

class HashTableQ // quadratic probing
{
private:
	int m; // the size of the table
	ElementQ * T; // the hash table
	int Hash(int); // the hash function
	const int RADIUS_MILES = 3961;
	int QuadraticProbe(int x, int i); // the quadratic probing function

public:
	HashTableQ(int size); // set the size of the table
	void Insert(string x, double y, double z); // insert a new element with key x
	void Remove(string x); // remove an element whose key is x
	bool Search(string x); // search an element whose key is x and return true if found
	double ComputeDistance(string x1, string x2); // return the distance between two zip codes.
												  // assume both zip codes are valid ones.
	void PrintTableEntry(); // print the element in the hash table
};
#pragma once
